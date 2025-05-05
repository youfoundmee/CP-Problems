#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// FIFO Algorithm
int fifo(const vector<int>& pages, int capacity) {
    unordered_set<int> memory;
    queue<int> q;
    int faults = 0;

    for (int page : pages) {
        if (memory.find(page) == memory.end()) {
            // Page fault
            faults++;
            if (memory.size() == capacity) {
                int old = q.front();
                q.pop();
                memory.erase(old);
            }
            memory.insert(page);
            q.push(page);
        }
    }
    return faults;
}

// LRU Algorithm
int lru(const vector<int>& pages, int capacity) {
    unordered_set<int> memory;
    unordered_map<int, int> recent; // Page -> most recent use index
    int faults = 0;

    for (int i = 0; i < pages.size(); i++) {
        int page = pages[i];
        if (memory.find(page) == memory.end()) {
            // Page fault
            faults++;
            if (memory.size() == capacity) {
                // Find least recently used
                int lruPage = -1, lruIndex = i;
                for (int p : memory) {
                    if (recent[p] < lruIndex) {
                        lruIndex = recent[p];
                        lruPage = p;
                    }
                }
                memory.erase(lruPage);
            }
            memory.insert(page);
        }
        recent[page] = i;
    }
    return faults;
}

// Optimal Algorithm
int optimal(const vector<int>& pages, int capacity) {
    unordered_set<int> memory;
    int faults = 0;

    for (int i = 0; i < pages.size(); i++) {
        int page = pages[i];
        if (memory.find(page) == memory.end()) {
            faults++;
            if (memory.size() < capacity) {
                memory.insert(page);
            } else {
                // Replace page that won't be used for the longest time
                int index = -1, farthest = i + 1;
                for (int p : memory) {
                    int j;
                    for (j = i + 1; j < pages.size(); j++) {
                        if (pages[j] == p) break;
                    }
                    if (j > farthest) {
                        farthest = j;
                        index = p;
                    }
                    if (j == pages.size()) {
                        index = p;
                        break;
                    }
                }
                memory.erase(index);
                memory.insert(page);
            }
        }
    }
    return faults;
}

int main() {
    vector<int> referenceString;
    int num, frames;

    cout << "Enter reference string (end with -1): ";
    while (cin >> num && num != -1)
        referenceString.push_back(num);

    cout << "Enter number of page frames: ";
    cin >> frames;

    cout << "\n--- Page Replacement Algorithms ---\n";
    cout << "FIFO Page Faults: " << fifo(referenceString, frames) << endl;
    cout << "LRU Page Faults: " << lru(referenceString, frames) << endl;
    cout << "Optimal Page Faults: " << optimal(referenceString, frames) << endl;

    return 0;
}
