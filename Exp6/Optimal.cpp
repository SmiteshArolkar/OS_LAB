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

void displayFrames(set<Page>& frameSet) {
    cout << "Current Frames: ";
    for (const Page& page : frameSet) {
        cout << page.pageNumber << " ";
    }
    cout << endl;
}

int optimalPageReplacement(int pages[], int n, int capacity, int futureReferences[], int futureReferencesCount) {
    unordered_map<int, int> pageLastUse;
    int pageFaults = 0;
    set<Page> frameSet;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        cout << "Iteration " << i + 1 << ": Page " << pages[i] << " - ";

        if (pageLastUse.find(pages[i]) == pageLastUse.end()) {
            if (frameSet.size() < capacity) {
                pageLastUse[pages[i]] = i;
                frameSet.insert(Page(pages[i], 0, i));
                pageFaults++;
                displayFrames(frameSet);
                cout << "Page loaded into memory (Page Fault)" << endl;
            } else {
                int pageToReplace = -1;
                int farthestUse = INT_MIN;

                for (const Page& framePage : frameSet) {
                    if (futureReferencesCount <= i) {
                        pageToReplace = framePage.pageNumber;
                        break;
                    } else {
                        int nextUse = INT_MAX;
                        for (int k = i + 1; k < futureReferencesCount; k++) {
                            if (futureReferences[k] == framePage.pageNumber) {
                                nextUse = k;
                                break;
                            }
                        }
                        if (nextUse > farthestUse) {
                            farthestUse = nextUse;
                            pageToReplace = framePage.pageNumber;
                        }
                    }
                }

                frameSet.erase(Page(pageToReplace, 0, 0));
                pageLastUse.erase(pageToReplace);

                pageLastUse[pages[i]] = i;
                frameSet.insert(Page(pages[i], 0, i));
                pageFaults++;
                displayFrames(frameSet);
                cout << "Page " << pageToReplace << " replaced by Page " << pages[i] << " (Page Fault)" << endl;
            }
        } else {
            displayFrames(frameSet);
            cout << "Page already in memory" << endl;
        }
    }

    return pageFaults;
}

int main() {
    int n, capacity, futureReferencesCount;

    cout << "Enter the number of page references: ";
    cin >> n;

    int pages[n];
    cout << "Enter the page reference string: ";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << "Enter the number of frames (capacity): ";
    cin >> capacity;

    cout << "Enter the number of future references: ";
    cin >> futureReferencesCount;

    int futureReferences[futureReferencesCount];
    cout << "Enter the future reference string: ";
    for (int i = 0; i < futureReferencesCount; i++) {
        cin >> futureReferences[i];
    }

    int pageFaults = optimalPageReplacement(pages, n, capacity, futureReferences, futureReferencesCount);
    cout << "Total page faults: " << pageFaults << endl;

    return 0;
}
