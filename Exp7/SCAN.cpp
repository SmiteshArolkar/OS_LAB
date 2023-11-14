#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate total seek time for SCAN
int calculateTotalSeekTimeSCAN(const vector<int>& requestOrder, int initialPosition, bool leftToRight) {
    int totalSeekTime = 0;

    // Create two vectors to store requests on the left and right sides of the initial position
    vector<int> leftRequests;
    vector<int> rightRequests;

    // Partition the requests based on their position relative to the initial position
    for (int request : requestOrder) {
        if (request < initialPosition) {
            leftRequests.push_back(request);
        } else {
            rightRequests.push_back(request);
        }
    }

    // Sort the left and right request vectors
    sort(leftRequests.begin(), leftRequests.end());
    sort(rightRequests.begin(), rightRequests.end());

    // If the direction is left to right, process right requests first, then left
    if (leftToRight) {
        for (int request : rightRequests) {
            totalSeekTime += abs(initialPosition - request);
            initialPosition = request;
        }

        for (int request : leftRequests) {
            totalSeekTime += abs(initialPosition - request);
            initialPosition = request;
        }
    }
    // If the direction is right to left, process left requests first, then right
    else {
        for (int request : leftRequests) {
            totalSeekTime += abs(initialPosition - request);
            initialPosition = request;
        }

        for (int request : rightRequests) {
            totalSeekTime += abs(initialPosition - request);
            initialPosition = request;
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

    // Get user input for the direction (L for left, R for right)
    cout << "Enter the direction (L for left, R for right): ";
    cin >> direction;

    vector<int> requestOrder(numRequests);

    // Get user input for the request order
    cout << "Enter the disk request order:\n";
    for (int i = 0; i < numRequests; ++i) {
        cout << "Request " << i + 1 << ": ";
        cin >> requestOrder[i];
    }

    // Calculate and display total seek time for SCAN
    int totalSeekTimeSCAN = calculateTotalSeekTimeSCAN(requestOrder, initialPosition, (direction == 'R'));
    cout << "Total Seek Time using SCAN: " << totalSeekTimeSCAN << endl;

    return 0;
}
