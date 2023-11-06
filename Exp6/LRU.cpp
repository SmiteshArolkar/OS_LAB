#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

int lruPageReplacement(int pages[], int n, int capacity) {
    list<int> pageList;
    unordered_map<int, list<int>::iterator> pageMap;
    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        cout << "Iteration " << i + 1 << ": Page " << pages[i] << " - ";

        if (pageMap.find(pages[i]) == pageMap.end()) {
            if (pageList.size() == capacity) {
                int leastRecentlyUsed = pageList.back();
                pageList.pop_back();
                pageMap.erase(leastRecentlyUsed);
            }
            pageFaults++;
            cout << "Page loaded into memory (Page Fault)" << endl;
        } else {
            pageList.erase(pageMap[pages[i]]);
            cout << "Page already in memory" << endl;
        }

        pageList.push_front(pages[i]);
        pageMap[pages[i]] = pageList.begin();
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

    int pageFaults = lruPageReplacement(pages, n, capacity);
    cout << "Total page faults: " << pageFaults << endl;

    return 0;
}
