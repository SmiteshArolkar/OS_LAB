#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate total seek time for SSTF
int calculateTotalSeekTimeSSTF(vector<int>& requestOrder, int initialPosition) {
    int totalSeekTime = 0;
    int currentPos = initialPosition;

    // Sort the request order based on the absolute difference from the current position
    sort(requestOrder.begin(), requestOrder.end(), [currentPos](int a, int b) {
        return abs(a - currentPos) < abs(b - currentPos);
    });

    // Iterate through the sorted request order
    for (int request : requestOrder) {
        // Calculate the absolute difference between current and requested position
        totalSeekTime += abs(currentPos - request);
        // Update current position
        currentPos = request;
    }

    return totalSeekTime;
}

int main() {
    int numRequests, initialPosition;

    // Get user input for the number of requests
    cout << "Enter the number of disk requests: ";
    cin >> numRequests;

    // Get user input for the initial position
    cout << "Enter the initial position of the disk arm: ";
    cin >> initialPosition;

    vector<int> requestOrder(numRequests);

    // Get user input for the request order
    cout << "Enter the disk request order:\n";
    for (int i = 0; i < numRequests; ++i) {
        cout << "Request " << i + 1 << ": ";
        cin >> requestOrder[i];
    }

    // Calculate and display total seek time for SSTF
    int totalSeekTimeSSTF = calculateTotalSeekTimeSSTF(requestOrder, initialPosition);
    cout << "Total Seek Time using SSTF: " << totalSeekTimeSSTF << endl;

    return 0;
}
