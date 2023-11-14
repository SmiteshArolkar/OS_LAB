#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate total seek time for LOOK
int calculateTotalSeekTimeLOOK(const vector<int>& requestOrder, int initialPosition, bool lookUp) {
    int totalSeekTime = 0;

    // Sort the request order
    vector<int> sortedRequests = requestOrder;
    sort(sortedRequests.begin(), sortedRequests.end());

    // Find the position of the initial position in the sorted order
    auto it = find(sortedRequests.begin(), sortedRequests.end(), initialPosition);

    // If the initial position is not found, insert it at the appropriate position
    if (it == sortedRequests.end()) {
        sortedRequests.push_back(initialPosition);
        sort(sortedRequests.begin(), sortedRequests.end());
        it = find(sortedRequests.begin(), sortedRequests.end(), initialPosition);
    }

    // Iterate through the sorted order, starting from the initial position
    for (auto iter = it; iter != sortedRequests.end(); ++iter) {
        totalSeekTime += abs(initialPosition - *iter);
        initialPosition = *iter;
    }

    // If looking up, move to the beginning of the disk and iterate in reverse
    if (lookUp) {
        for (auto iter = sortedRequests.rbegin(); iter != it; ++iter) {
            totalSeekTime += abs(initialPosition - *iter);
            initialPosition = *iter;
        }
    }
    // If looking down, move to the end of the disk and iterate in reverse
    else {
        for (auto iter = sortedRequests.rbegin(); iter != sortedRequests.rend(); ++iter) {
            totalSeekTime += abs(initialPosition - *iter);
            initialPosition = *iter;
        }
    }

    return totalSeekTime;
}

int main() {
    int numRequests, initialPosition;
    char direction;

    // Get user input for the number of requests
    cout << "Enter the number of disk requests: ";
    cin >> numRequests;

    // Get user input for the initial position
    cout << "Enter the initial position of the disk arm: ";
    cin >> initialPosition;

    // Get user input for the direction (U for up, D for down)
    cout << "Enter the direction (U for up, D for down): ";
    cin >> direction;

    vector<int> requestOrder(numRequests);

    // Get user input for the request order
    cout << "Enter the disk request order:\n";
    for (int i = 0; i < numRequests; ++i) {
        cout << "Request " << i + 1 << ": ";
        cin >> requestOrder[i];
    }

    // Calculate and display total seek time for LOOK
    int totalSeekTimeLOOK = calculateTotalSeekTimeLOOK(requestOrder, initialPosition, (direction == 'U'));
    cout << "Total Seek Time using LOOK: " << totalSeekTimeLOOK << endl;

    return 0;
}
