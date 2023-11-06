#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

struct Page {
    int pageNumber;
    int frequency;
    int time;

    Page(int num, int freq, int t) : pageNumber(num), frequency(freq), time(t) {}

    bool operator<(const Page& other) const {
        if (frequency == other.frequency)
            return time < other.time;
        return frequency < other.frequency;
    }
};

int lfuPageReplacement(int pages[], int n, int capacity) {
    unordered_map<int, int> pageFrequency;
    set<Page> pageSet;
    int pageFaults = 0;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        cout << "Iteration " << i + 1 << ": Page " << pages[i] << " - ";

        if (pageFrequency.find(pages[i]) == pageFrequency.end()) {
            if (pageFrequency.size() == capacity) {
                Page leastFrequentPage = *pageSet.begin();
                pageSet.erase(leastFrequentPage);
                pageFrequency.erase(leastFrequentPage.pageNumber);
            }
            pageFaults++;
            cout << "Page loaded into memory (Page Fault)" << endl;
        } else {
            Page pageToRemove(pages[i], pageFrequency[pages[i]], currentTime);
            pageSet.erase(pageToRemove);
            cout << "Page already in memory" << endl;
        }

        pageFrequency[pages[i]]++;
        pageSet.insert(Page(pages[i], pageFrequency[pages[i]], currentTime));
        currentTime++;
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

    int pageFaults = lfuPageReplacement(pages, n, capacity);
    cout << "Total page faults: " << pageFaults << endl;

    return 0;
}
