/*
CSC113 
Project Phase 3
Group: Melissa Martinez, Ferdus Rifa, Tehseen Chowdhury
*/

#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    int ID;
    double balance;
    string name;

public:
    // Constructor
    Account(double initialBalance = 0.0, const string& customerName = "", int id = 0)
        : ID(id), balance(initialBalance), name(customerName) {
        if (initialBalance < 0) {
            balance = 0.0;
            cout << "Error: Initial account balance is invalid. Setting balance to 0." << endl;
        }
    }

    // Accessors
    int getAccountID() const {
        return ID;
    }

    string getCustomerName() const {
        return name;
    }

    double getBalance() const {
        return balance;
    }

    // Mutators
    void setCustomerName(const string& newName) {
        name = newName;
    }

    void setAccountID(int newID) {
        ID = newID;
    }

    // Member functions
    void credit(double amount) {
        balance += amount;
    }

    void debit(double amount) {
        if (amount > balance) {
            cout << "Debit amount exceeds the balance value." << endl;
        } else {
            balance -= amount;
        }
    }
};

// Function to display account information
void displayAccountInfo(const Account& acc) {
    cout << "Account ID: " << acc.getAccountID() << ", Name: " << acc.getCustomerName()
         << ", Balance: " << acc.getBalance() << endl;
}

int main() {
    const int MAX_CUSTOMERS = 5; // Maximum number of customers
    Account accounts[MAX_CUSTOMERS]; // Array to store account information

    // Read input for 5 customers
    for (int i = 0; i < MAX_CUSTOMERS; ++i) {
        int id;
        string name;
        double balance;

        cout << "Enter details for customer " << (i + 1) << ":" << endl;
        cout << "ID: ";
        cin >> id;
        cout << "Name: ";
        cin >> name;
        cout << "Initial Balance: ";
        cin >> balance;

        // Creating an Account object and store it in the accounts array
        accounts[i] = Account(balance, name, id);
    }

    int choice = -1;
    while (choice != 7) {
        // Display menu
        cout << "\nMenu:\n"
             << "1. Display balance (by Account ID)\n"
             << "2. Credit amount (by Account ID)\n"
             << "3. Debit amount (by Account ID)\n"
             << "4. Display all customers information in ascending order based on balance\n"
             << "5. Display all customers information in ascending order based on ID\n"
             << "6. Display all customers information in ascending order based on name\n"
             << "7. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // Display balance by Account ID
            int id;
            cout << "Enter Account ID: ";
            cin >> id;
            bool found = false;
            for (int i = 0; i < MAX_CUSTOMERS; ++i) {
                if (accounts[i].getAccountID() == id) {
                    displayAccountInfo(accounts[i]);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Account not found." << endl;
            }
        } else if (choice == 2) {
            // Credit amount by Account ID
            int id;
            double amount;
            cout << "Enter Account ID: ";
            cin >> id;
            cout << "Enter amount to credit: ";
            cin >> amount;
            for (int i = 0; i < MAX_CUSTOMERS; ++i) {
                if (accounts[i].getAccountID() == id) {
                    accounts[i].credit(amount);
                    cout << "Amount credited successfully." << endl;
                    displayAccountInfo(accounts[i]);
                    break;
                }
            }
        } else if (choice == 3) {
            // Debit amount by Account ID
            int id;
            double amount;
            cout << "Enter Account ID: ";
            cin >> id;
            cout << "Enter amount to debit: ";
            cin >> amount;
            for (int i = 0; i < MAX_CUSTOMERS; ++i) {
                if (accounts[i].getAccountID() == id) {
                    accounts[i].debit(amount);
                    displayAccountInfo(accounts[i]);
                    break;
                }
            }
        } else if (choice == 4) {
            // Display all customers information in ascending order based on balance
            // selection sort 
            for (int i = 0; i < MAX_CUSTOMERS - 1; ++i) {
                int minIndex = i;
                for (int j = i + 1; j < MAX_CUSTOMERS; ++j) {
                    if (accounts[j].getBalance() < accounts[minIndex].getBalance()) {
                        minIndex = j;
                    }
                }
                if (minIndex != i) {
                    swap(accounts[i], accounts[minIndex]);
                }
            }
            cout << "Customers sorted by balance:" << endl;
            for (int i = 0; i < MAX_CUSTOMERS; ++i) {
                displayAccountInfo(accounts[i]);
            }
        } else if (choice == 5) {
            // Display all customers information in ascending order based on ID
            // selection sort 
            for (int i = 0; i < MAX_CUSTOMERS - 1; ++i) {
                int minIndex = i;
                for (int j = i + 1; j < MAX_CUSTOMERS; ++j) {
                    if (accounts[j].getAccountID() < accounts[minIndex].getAccountID()) {
                        minIndex = j;
                    }
                }
                if (minIndex != i) {
                    swap(accounts[i], accounts[minIndex]);
                }
            }
            cout << "Customers sorted by ID:" << endl;
            for (int i = 0; i < MAX_CUSTOMERS; ++i) {
                displayAccountInfo(accounts[i]);
            }
        } else if (choice == 6) {
            // Display all customers information in ascending order based on name
            // selection sort
            for (int i = 0; i < MAX_CUSTOMERS - 1; ++i) {
                int minIndex = i;
                for (int j = i + 1; j < MAX_CUSTOMERS; ++j) {
                    if (accounts[j].getCustomerName() < accounts[minIndex].getCustomerName()) {
                        minIndex = j;
                    }
                }
                if (minIndex != i) {
                    swap(accounts[i], accounts[minIndex]);
                }
            }
            cout << "Customers sorted by name:" << endl;
            for (int i = 0; i < MAX_CUSTOMERS; ++i) {
                displayAccountInfo(accounts[i]);
            }
        } else if (choice == 7) {
            // Exit the program
            cout << "Exiting program..." << endl;
        } else {
            // Invalid choice handling
            cout << "Invalid choice. Please enter a number from 1 to 7." << endl;
        }
    }

    return 0;
}
