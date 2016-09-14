//
//  main.cpp
//  AdressBook
//
//  Created by victor on 13/09/16.
//  Copyright © 2016 victor. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

void showAll(map<string, vector<string>> adressList, int num) {
    if (num == 0) {
        cout << "Sorry, your contact list is empty!" << endl;
    } else {
        cout << "--------------------------------------------------------------------" << endl;
        cout << "| Name                 | Phone              | City                 |" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        int n = 1;
        for(auto elem : adressList) {
            auto tempVector = elem.second;
            ostringstream out;
            out << n;
            string numberStr = out.str();
            cout << "| " << numberStr << ". " << tempVector[0];
            for(int k = 0; k<(21-numberStr.length() - 2 - tempVector[0].length()); k++) {
                cout << " ";
            }
            cout << "| " << elem.first;
            for(int k = 0; k<(19-elem.first.length()); k++) {
                cout << " ";
            }
            cout << "| " << tempVector[1];
            for(int k = 0; k<(21-tempVector[1].length()); k++) {
                cout << " ";
            }
            cout << "|" << endl;
            n++;
        }
        cout << "--------------------------------------------------------------------" << endl;
    }
}

void addNew(map<string, vector<string>> &adressList, int &num) {
    string tempName, tempNumber, tempCity;
    cout << "Enter name: ";
    cin >> tempName;
    cout << "Enter number: ";
    cin >> tempNumber;
    cout << "Enter city: ";
    cin >> tempCity;
    ofstream sourceFile("adressBookCPP.txt", ios_base::app);
    if(num == 0)
        sourceFile << tempName << " " << tempNumber << " " << tempCity;
    else
        sourceFile << endl << tempName << " " << tempNumber << " " << tempCity;
    sourceFile.close();
    vector<string> tempVector(2);
    tempVector[0] = tempName;
    tempVector[1] = tempCity;
    adressList.insert(pair<string, vector<string>>(tempNumber, tempVector));
    num++;
}

void searchName(map<string, vector<string>> adressList, int num) {
    int amount = 0;
    cout << "Enter NAME: ";
    string tempName;
    cin >> tempName;
    for(auto iter : adressList) {
        auto tempVector = iter.second;
        if(tempVector[0] == tempName) {
            if (amount == 0) {
                cout << "--------------------------------------------------------------------" << endl;
                cout << "| Name                 | Phone              | City                 |" << endl;
                cout << "--------------------------------------------------------------------" << endl;
            }
            cout << "| " << tempVector[0];
            for(int k = 0; k<(21-tempVector[0].length()); k++) {
                cout << " ";
            }
            cout << "| " << iter.first;
            for(int k = 0; k<(19-iter.first.length()); k++) {
                cout << " ";
            }
            cout << "| " << tempVector[1];
            for(int k = 0; k<(21-tempVector[1].length()); k++) {
                cout << " ";
            }
            cout << "|" << endl;
            amount++;
        }
    }
    cout << "--------------------------------------------------------------------" << endl;
    if(amount != 0) {
        if(amount == 1)
            cout << "Found " << amount << " contact." << endl;
        else if (amount > 1)
            cout << "Found " << amount << " contacts." << endl;
    } else
        cout << "Sorry. We could not find any contact with name " << tempName << "." << endl;
    cout << ("Search completed!") << endl;
}

void searchNumber(map<string, vector<string>> adressList, int num) {
    int amount = 0;
    cout << "Enter NUMBER: ";
    string tempNumber;
    cin >> tempNumber;
    for(auto iter : adressList) {
        auto tempVector = iter.second;
        if(iter.first == tempNumber) {
            if (amount == 0) {
                cout << "--------------------------------------------------------------------" << endl;
                cout << "| Name                 | Phone              | City                 |" << endl;
                cout << "--------------------------------------------------------------------" << endl;
            }
            cout << "| " << tempVector[0];
            for(int k = 0; k<(21-tempVector[0].length()); k++) {
                cout << " ";
            }
            cout << "| " << iter.first;
            for(int k = 0; k<(19-iter.first.length()); k++) {
                cout << " ";
            }
            cout << "| " << tempVector[1];
            for(int k = 0; k<(21-tempVector[1].length()); k++) {
                cout << " ";
            }
            cout << "|" << endl;
            amount++;
        }
    }
    cout << "--------------------------------------------------------------------" << endl;
    if(amount != 0) {
        if(amount == 1)
            cout << "Found " << amount << " contact." << endl;
        else if (amount > 1)
            cout << "Found " << amount << " contacts." << endl;
    } else
        cout << "Sorry. We could not find any contact with phone number " << tempNumber << "." << endl;
    cout << ("Search completed!") << endl;
}

void searchCity(map<string, vector<string>> adressList, int num) {
    int amount = 0;
    cout << "Enter CITY: ";
    string tempCity;
    cin >> tempCity;
    for(auto iter : adressList) {
        auto tempVector = iter.second;
        if(tempVector[1] == tempCity) {
            if (amount == 0) {
                cout << "--------------------------------------------------------------------" << endl;
                cout << "| Name                 | Phone              | City                 |" << endl;
                cout << "--------------------------------------------------------------------" << endl;
            }
            cout << "| " << tempVector[0];
            for(int k = 0; k<(21-tempVector[0].length()); k++) {
                cout << " ";
            }
            cout << "| " << iter.first;
            for(int k = 0; k<(19-iter.first.length()); k++) {
                cout << " ";
            }
            cout << "| " << tempVector[1];
            for(int k = 0; k<(21-tempVector[1].length()); k++) {
                cout << " ";
            }
            cout << "|" << endl;
            amount++;
        }
    }
    cout << "--------------------------------------------------------------------" << endl;
    if(amount != 0) {
        if(amount == 1)
            cout << "Found " << amount << " contact." << endl;
        else if (amount > 1)
            cout << "Found " << amount << " contacts." << endl;
    } else
        cout << "Sorry. We could not find any contact from " << tempCity << "." << endl;
    cout << ("Search completed!") << endl;
}

void search(map<string, vector<string>> adressList, int num) {
    cout << "-------------------------------SEARCH-------------------------------" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "|       1. Name        |   2. Phone number  |       3. City        |" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Enter number of menu item: ";
    
    int menuItem;
    cin >> menuItem;
    
    switch(menuItem) {
        case 1:
            searchName(adressList, num);
            break;
        case 2:
            searchNumber(adressList, num);
            break;
        case 3:
            searchCity(adressList, num);
            break;
        default:
            cout << "Cancel..." << endl;
            break;
    }
}

int main() {
    map<string, vector<string>> adressList;
    
    int num = 0;
    
    string tempName, tempNumber, tempCity;
    
    /*ofstream fout("adressBookCPP.txt"); // Create file
     fout.close();*/
    
    ifstream sourceFile("adressBookCPP.txt", ios_base::in);
    
    while(!sourceFile.eof()) {
        sourceFile >> tempName;
        if (tempName != "") {
            sourceFile >> tempNumber;
            sourceFile >> tempCity;
            vector<string> tempVector(2);
            tempVector[0] = tempName;
            tempVector[1] = tempCity;
            adressList.insert(pair<string, vector<string>>(tempNumber, tempVector));
            num++;
        }
    }
    
    bool ind = true;
    while(ind) {
        cout << "------------------------------CONTACTS------------------------------" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "|   1. Show all   |    2. Add new    |   3. Search   |   4. Exit   |" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "Enter number of menu item: ";
        
        int menuItem = 0;
        cin >> menuItem;
        
        switch(menuItem) {
            case 1:
                showAll(adressList, num);
                break;
            case 2:
                addNew(adressList, num);
                break;
            case 3:
                search(adressList, num);
                break;
            case 4:
                ind = false;
                break;
            default:
                cout << "Unknow menu item!" << endl;
        }
    }
}