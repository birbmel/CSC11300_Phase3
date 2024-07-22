// Tehseen Chowdhury, Ferdus Rifa, Melissa Martinez

#include <iostream>
using namespace std;

void displayMenu() {
    cout << "Please type 1 for \"Reservation\"\n";
    cout << "Please type 2 for \"Cancelling\"\n";
    cout << "Please type 3 for \"Displaying all seats\"\n";
    cout << "Please type 0 to \"Exit\"\n";
}

void displaySeats(bool seats[10][10]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
}

void reserveSeat(bool seats[10][10]) {
    int row, col;
    cout << "Enter row (1-10): ";
    cin >> row;
    cout << "Enter column (1-10): ";
    cin >> col;

    if (row < 1 || row > 10 || col < 1 || col > 10) {
        cout << "Invalid seat coordinates.\n";
        return;
    }

    if (seats[row-1][col-1]) {
        cout << "Seat is already reserved.\n";
    } else {
        seats[row-1][col-1] = true;
        cout << "Seat reserved successfully.\n";
    }
}

void cancelReservation(bool seats[10][10]) {
    int row, col;
    cout << "Enter row (1-10): ";
    cin >> row;
    cout << "Enter column (1-10): ";
    cin >> col;

    if (row < 1 || row > 10 || col < 1 || col > 10) {
        cout << "Invalid seat coordinates.\n";
        return;
    }

    if (!seats[row-1][col-1]) {
        cout << "Seat is not reserved.\n";
    } else {
        seats[row-1][col-1] = false;
        cout << "Reservation cancelled successfully.\n";
    }
}

int main() {
    bool seats[10][10] = {false}; 
    int option;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                reserveSeat(seats);
                break;
            case 2:
                cancelReservation(seats);
                break;
            case 3:
                displaySeats(seats);
                break;
            case 0:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (option != 0);

    return 0;
}
