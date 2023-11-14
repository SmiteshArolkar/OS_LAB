#include <iostream>
#include <vector>

using namespace std;

// Function to calculate total seek time for FCFS
int calculateTotalSeekTime(const vector<int>& requestOrder, int initialPosition) {
    int totalSeekTime = 0;
    int currentPos = initialPosition;

    // Iterate through the request order
    for (int request : requestOrder) {
        // In FCFS, there is no seeking, just processing in order
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

    // Calculate and display total seek time for FCFS
    int totalSeekTime = calculateTotalSeekTime(requestOrder, initialPosition);
    cout << "Total Seek Time using FCFS: " << totalSeekTime << endl;

    return 0;
}
