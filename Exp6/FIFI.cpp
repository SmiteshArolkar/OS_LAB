#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int fifoPageReplacement(int pages[], int n, int capacity) {
    queue<int> pageQueue;
    unordered_set<int> pageSet;
    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        cout << "Iteration " << i + 1 << ": Page " << pages[i] << " - ";

        if (pageSet.size() < capacity) {
            if (pageSet.find(pages[i]) == pageSet.end()) {
                pageSet.insert(pages[i]);
                pageQueue.push(pages[i]);
                pageFaults++;
                cout << "Page loaded into memory (Page Fault)" << endl;
            } else {
                cout << "Page already in memory" << endl;
            }
        } else {
            if (pageSet.find(pages[i]) == pageSet.end()) {
                int oldestPage = pageQueue.front();
                pageQueue.pop();
                pageSet.erase(oldestPage);
                pageSet.insert(pages[i]);
                pageQueue.push(pages[i]);
                pageFaults++;
                cout << "Page " << oldestPage << " replaced by Page " << pages[i] << " (Page Fault)" << endl;
            } else {
                cout << "Page already in memory" << endl;
            }
        }
    }

    return pageFaults;
}

int main() {
    int n, capacity;

    cout << "Enter the number of page references: ";
    cin >> n;

    int pages[n];
    cout << "Enter the page reference string: ";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << "Enter the number of frames (capacity): ";
    cin >> capacity;

    int pageFaults = fifoPageReplacement(pages, n, capacity);
    cout << "Total page faults: " << pageFaults << endl;

    return 0;
}
