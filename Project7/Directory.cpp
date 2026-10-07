#include "Directory.h"

Directory::Directory(string name) {
    fileName = name;
}

void Directory::addRecord() {
    string company, owner, phone, address, activity;
    cout << "\nCompany name: ";
    getline(cin, company);
    cout << "Owner: ";
    getline(cin, owner);
    cout << "Phone: ";
    getline(cin, phone);
    cout << "Address: ";
    getline(cin, address);
    cout << "Activity: ";
    getline(cin, activity);
    ofstream file(fileName, ios::app);
    file << company << endl;
    file << owner << endl;
    file << phone << endl;
    file << address << endl;
    file << activity << endl;
    file.close();
    cout << "\nRecord added successfully!\n";
}

void Directory::showAll() {
    ifstream file(fileName);
    string company, owner, phone, address, activity;
    bool empty = true;
    while (getline(file, company)) {
        getline(file, owner);
        getline(file, phone);
        getline(file, address);
        getline(file, activity);
        cout << "\n-----------------------------\n";
        cout << "Company:  " << company << endl;
        cout << "Owner:    " << owner << endl;
        cout << "Phone:    " << phone << endl;
        cout << "Address:  " << address << endl;
        cout << "Activity: " << activity << endl;
        empty = false;
    }
    file.close();
    if (empty)
        cout << "\nDirectory is empty.\n";
}

void Directory::searchByCompany() {
    string search;
    cout << "\nEnter company name: ";
    getline(cin, search);
    searchRecord(search, 1);
}

void Directory::searchByOwner() {
    string search;
    cout << "\nEnter owner name: ";
    getline(cin, search);
    searchRecord(search, 2);
}

void Directory::searchByPhone() {
    string search;
    cout << "\nEnter phone number: ";
    getline(cin, search);
    searchRecord(search, 3);
}

void Directory::searchByActivity() {
    string search;
    cout << "\nEnter activity: ";
    getline(cin, search);
    searchRecord(search, 5);
}

void Directory::searchRecord(string search, int field) {
    ifstream file(fileName);
    string company, owner, phone, address, activity;
    bool found = false;
    while (getline(file, company)) {
        getline(file, owner);
        getline(file, phone);
        getline(file, address);
        getline(file, activity);
        string value;
        if (field == 1)
            value = company;
        else if (field == 2)
            value = owner;
        else if (field == 3)
            value = phone;
        else if (field == 5)
            value = activity;
        if (value == search) {
            cout << "\n-----------------------------\n";
            cout << "Company:  " << company << endl;
            cout << "Owner:    " << owner << endl;
            cout << "Phone:    " << phone << endl;
            cout << "Address:  " << address << endl;
            cout << "Activity: " << activity << endl;
            found = true;
        }
    }
    file.close();
    if (!found)
        cout << "\nRecord not found.\n";
}
