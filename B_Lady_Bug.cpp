#include <bits/stdc++.h>

using namespace std;

// Structure to represent a memory block
struct MemoryBlock {
    int start_address;
    int size;
    bool allocated;
};

// List to store memory blocks
vector<MemoryBlock> memory;

// Function to display memory status
void displayMemory() {
    cout << "\nMemory Blocks:\n";
    cout << "Start Address\tSize\tStatus\n";
    for (const auto& block : memory) {
        cout << block.start_address << "\t\t" << block.size << "\t" 
             << (block.allocated ? "Allocated" : "Free") << "\n";
    }
    cout << "-------------------------------------\n";
}

// Function to merge adjacent free blocks
void mergeFreeBlocks() {
    for (size_t i = 0; i < memory.size() - 1; i++) {
        if (!memory[i].allocated && !memory[i + 1].allocated) {
            memory[i].size += memory[i + 1].size;
            memory.erase(memory.begin() + i + 1);
            i--; // Recheck merged block
        }
    }
}

// First Fit Allocation
void firstFit(int process_size) {
    for (auto& block : memory) {
        if (!block.allocated && block.size >= process_size) {
            block.allocated = true;
            if (block.size > process_size) {
                // Split block
                memory.insert(memory.begin() + (&block - &memory[0]) + 1, 
                              {block.start_address + process_size, block.size - process_size, false});
                block.size = process_size;
            }
            displayMemory();
            return;
        }
    }
    cout << "No suitable block found for process of size " << process_size << "\n";
}

// Best Fit Allocation
void bestFit(int process_size) {
    int bestIndex = -1, minSize = INT_MAX;
    
    for (size_t i = 0; i < memory.size(); i++) {
        if (!memory[i].allocated && memory[i].size >= process_size && memory[i].size < minSize) {
            bestIndex = i;
            minSize = memory[i].size;
        }
    }
    
    if (bestIndex != -1) {
        memory[bestIndex].allocated = true;
        if (memory[bestIndex].size > process_size) {
            // Split block
            memory.insert(memory.begin() + bestIndex + 1, 
                          {memory[bestIndex].start_address + process_size, memory[bestIndex].size - process_size, false});
            memory[bestIndex].size = process_size;
        }
        displayMemory();
    } else {
        cout << "No suitable block found for process of size " << process_size << "\n";
    }
}

// Worst Fit Allocation
void worstFit(int process_size) {
    int worstIndex = -1, maxSize = -1;
    
    for (size_t i = 0; i < memory.size(); i++) {
        if (!memory[i].allocated && memory[i].size >= process_size && memory[i].size > maxSize) {
            worstIndex = i;
            maxSize = memory[i].size;
        }
    }
    
    if (worstIndex != -1) {
        memory[worstIndex].allocated = true;
        if (memory[worstIndex].size > process_size) {
            // Split block
            memory.insert(memory.begin() + worstIndex + 1, 
                          {memory[worstIndex].start_address + process_size, memory[worstIndex].size - process_size, false});
            memory[worstIndex].size = process_size;
        }
        displayMemory();
    } else {
        cout << "No suitable block found for process of size " << process_size << "\n";
    }
}

// Function to deallocate memory
void deallocate(int start_address) {
    for (auto& block : memory) {
        if (block.start_address == start_address && block.allocated) {
            block.allocated = false;
            mergeFreeBlocks();
            displayMemory();
            return;
        }
    }
    cout << "Process not found at address " << start_address << "\n";
}

// Main function
int main() {
    // Initial memory blocks
    memory.push_back({0, 100, false});
    memory.push_back({100, 200, false});
    memory.push_back({300, 50, false});
    
    cout << "Initial Memory Status:";
    displayMemory();

    // Allocate using different strategies
    cout << "\nAllocating 90 using First Fit:";
    firstFit(90);
    
    cout << "\nAllocating 40 using Best Fit:";
    bestFit(40);
    
    cout << "\nAllocating 120 using Worst Fit:";
    worstFit(120);

    // Deallocation
    cout << "\nDeallocating process at 0:";
    deallocate(0);

    cout << "\nAllocating 60 using First Fit:";
    firstFit(60);

    return 0;
}
