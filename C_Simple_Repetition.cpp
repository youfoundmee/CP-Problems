#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    int logical_memory_size, physical_memory_size, page_size;

    cout << "Enter logical address space size (in bytes): ";
    cin >> logical_memory_size;

    cout << "Enter physical memory size (in bytes): ";
    cin >> physical_memory_size;

    cout << "Enter page size (in bytes): ";
    cin >> page_size;

    int num_pages = logical_memory_size / page_size;
    int num_frames = physical_memory_size / page_size;

    cout << "\nLogical address space has " << num_pages << " pages.\n";
    cout << "Physical memory has " << num_frames << " frames.\n";

    int num_addresses;
    cout << "\nEnter number of logical addresses to be translated: ";
    cin >> num_addresses;

    vector<int> logical_addresses(num_addresses);
    cout << "Enter logical addresses:\n";
    for (int i = 0; i < num_addresses; ++i) {
        cin >> logical_addresses[i];
    }

    unordered_map<int, int> page_table;         // page_number -> frame_number
    queue<int> loaded_pages;                    // FIFO page replacement
    int page_faults = 0;
    int frame_counter = 0;

    cout << "\nTranslation Results:\n";
    cout << "Logical Address | Page Number | Offset | Physical Address | Page Fault\n";
    cout << "--------------------------------------------------------------------------\n";

    for (int address : logical_addresses) {
        int page_number = address / page_size;
        int offset = address % page_size;
        bool page_fault = false;

        if (page_table.find(page_number) == page_table.end()) {
            // Page fault occurs
            page_faults++;
            page_fault = true;

            // Replace if no free frames
            if (page_table.size() == num_frames) {
                int to_remove = loaded_pages.front();
                loaded_pages.pop();
                page_table.erase(to_remove);
            }

            page_table[page_number] = frame_counter;
            loaded_pages.push(page_number);
            frame_counter = (frame_counter + 1) % num_frames;
        }

        int frame_number = page_table[page_number];
        int physical_address = frame_number * page_size + offset;

        cout << "      " << address
             << "         |     " << page_number
             << "       |   " << offset
             << "   |      " << physical_address
             << "       | " << (page_fault ? "Yes" : "No") << endl;
    }

    cout << "\nTotal Page Faults: " << page_faults << endl;

    
}
