#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Directory {
private:
    string fileName;
public:
    Directory(string name = "directory.txt");
    void addRecord();
    void showAll();
    void searchByCompany();
    void searchByOwner();
    void searchByPhone();
    void searchByActivity();
private:
    void searchRecord(string search, int field);
};

