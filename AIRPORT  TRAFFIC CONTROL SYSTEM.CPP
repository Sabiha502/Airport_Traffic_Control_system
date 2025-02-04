#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

// Class for Airport Traffic Control System
class AirportTrafficControl {
private:
    queue<string> landingQueue;  // Queue for landing flights
    queue<string> takeoffQueue; // Queue for takeoff flights
    stack<string> history;      // Stack to keep track of processed flights
    unordered_map<string, string> flightDetails; // Map to store additional flight details

public:
    // Add a flight to the landing queue
    void addLandingFlight(const string& flight, const string& details = "") {
        landingQueue.push(flight);
        if (!details.empty()) {
            flightDetails[flight] = details;
        }
        cout << "Flight " << flight << " added to the landing queue.\n";
    }

    // Add a flight to the takeoff queue
    void addTakeoffFlight(const string& flight, const string& details = "") {
        takeoffQueue.push(flight);
        if (!details.empty()) {
            flightDetails[flight] = details;
        }
        cout << "Flight " << flight << " added to the takeoff queue.\n";
    }

    // Process the next flight in the landing queue
    void processLanding() {
        if (landingQueue.empty()) {
            cout << "No flights in the landing queue.\n";
        } else {
            string flight = landingQueue.front();
            landingQueue.pop();
            history.push("Landed: " + flight);
            cout << "Flight " << flight << " has landed.\n";
            if (flightDetails.find(flight) != flightDetails.end()) {
                cout << "Details: " << flightDetails[flight] << "\n";
            }
        }
    }

    // Process the next flight in the takeoff queue
    void processTakeoff() {
        if (takeoffQueue.empty()) {
            cout << "No flights in the takeoff queue.\n";
        } else {
            string flight = takeoffQueue.front();
            takeoffQueue.pop();
            history.push("Took off: " + flight);
            cout << "Flight " << flight << " has taken off.\n";
            if (flightDetails.find(flight) != flightDetails.end()) {
                cout << "Details: " << flightDetails[flight] << "\n";
            }
        }
    }

    // Display the current schedule of flights
    void displaySchedule() {
        cout << "\nCurrent Landing Queue: ";
        if (landingQueue.empty()) {
            cout << "[Empty]\n";
        } else {
            queue<string> temp = landingQueue;
            while (!temp.empty()) {
                cout << temp.front();
                if (flightDetails.find(temp.front()) != flightDetails.end()) {
                    cout << " (" << flightDetails[temp.front()] << ")";
                }
                cout << " ";
                temp.pop();
            }
            cout << "\n";
        }

        cout << "Current Takeoff Queue: ";
        if (takeoffQueue.empty()) {
            cout << "[Empty]\n";
        } else {
            queue<string> temp = takeoffQueue;
            while (!temp.empty()) {
                cout << temp.front();
                if (flightDetails.find(temp.front()) != flightDetails.end()) {
                    cout << " (" << flightDetails[temp.front()] << ")";
                }
                cout << " ";
                temp.pop();
            }
            cout << "\n";
        }
    }

    // Display the history of processed flights
    void displayHistory() {
        cout << "\nHistory of Processed Flights: \n";
        if (history.empty()) {
            cout << "No flights have been processed yet.\n";
        } else {
            stack<string> temp = history;
            while (!temp.empty()) {
                cout << temp.top() << "\n";
                temp.pop();
            }
        }
    }

    // Search for a flight and display its details
    void searchFlight(const string& flight) {
        cout << "\nSearching for flight: " << flight << "\n";
        if (flightDetails.find(flight) != flightDetails.end()) {
            cout << "Details: " << flightDetails[flight] << "\n";
        } else {
            cout << "Flight not found in the records.\n";
        }
    }
};

int main() {
    AirportTrafficControl controlSystem;
    int choice;
    string flight, details;

    do {
        cout << "\n--- Airport Traffic Control System ---\n";
        cout << "1. Add Landing Flight\n";
        cout << "2. Add Takeoff Flight\n";
        cout << "3. Process Landing\n";
        cout << "4. Process Takeoff\n";
        cout << "5. Display Schedule\n";
        cout << "6. Display History\n";
        cout << "7. Search for a Flight\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter flight number for landing: ";
                cin >> flight;
                cout << "Enter additional details (optional): ";
                cin.ignore();
                getline(cin, details);
                controlSystem.addLandingFlight(flight, details);
                break;
            case 2:
                cout << "Enter flight number for takeoff: ";
                cin >> flight;
                cout << "Enter additional details (optional): ";
                cin.ignore();
                getline(cin, details);
                controlSystem.addTakeoffFlight(flight, details);
                break;
            case 3:
                controlSystem.processLanding();
                break;
            case 4:
                controlSystem.processTakeoff();
                break;
            case 5:
                controlSystem.displaySchedule();
                break;
            case 6:
                controlSystem.displayHistory();
                break;
            case 7:
                cout << "Enter flight number to search: ";
                cin >> flight;
                controlSystem.searchFlight(flight);
                break;
            case 8:
                cout << "Exiting the system.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
