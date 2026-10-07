#include <iostream>
#include <fstream>
#include <string>
#include "Directory.h"

using namespace std;

int main() {
    Directory directory;
    int choice;
    do {
        cout << "\n========== DIRECTORY ==========\n";
        cout << "1. Add record\n";
        cout << "2. Search by company name\n";
        cout << "3. Search by owner\n";
        cout << "4. Search by phone\n";
        cout << "5. Search by activity\n";
        cout << "6. Show all records\n";
        cout << "0. Exit\n";
        cout << "===============================\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1:
            directory.addRecord();
            break;
        case 2:
            directory.searchByCompany();
            break;
        case 3:
            directory.searchByOwner();
            break;
        case 4:
            directory.searchByPhone();
            break;
        case 5:
            directory.searchByActivity();
            break;
        case 6:
            directory.showAll();
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}

