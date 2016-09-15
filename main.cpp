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

using namespace std;

void SaveChanges(map<string, vector<string> > adressList, int num, int &recInd, string recPointer, int &recAmount, bool exitInd, vector<string> &recVector) {
    if ((exitInd == false && recAmount % 5 == 0 && recInd == 1) || ((exitInd == true) && (recInd == 1) && ((recAmount % 5 == 0) || (recAmount % 5 != 0)))) {
        ofstream sourceFile("adressBookCPP.txt", ios_base::app);
        for(int i = 0; i<recAmount; i++) {
            auto tempIter = adressList[recVector[i]];
            if(num == 0)
                sourceFile << tempIter[0] << " " << recVector[i] << " " << tempIter[1];
            else
                sourceFile << endl << tempIter[0] << " " << recVector[i] << " " << tempIter[1];
        }
        sourceFile.close();
        recInd = 0;
        recAmount = 0;
    }
}

void rewriteFile(map<string, vector<string> > adressList) {
    int num = 0;
    ofstream sourceFile("adressBookCPP.txt");
    for (auto iter : adressList) {
        auto tempVector = iter.second;
        if(num == 0)
            sourceFile << tempVector[0] << " " << iter.first << " " << tempVector[1];
        else
            sourceFile << endl << tempVector[0] << " " << iter.first << " " << tempVector[1];
        num++;
    }
    sourceFile.close();
}

void changeName(map<string, vector<string> > &adressList, string contactPhoneNumber) {
    auto tempVector = adressList[contactPhoneNumber];
    adressList.erase(contactPhoneNumber);
    string tempName;
    cout << "Enter new name: ";
    cin >> tempName;
    tempVector[0] = tempName;
    adressList.insert(pair<string, vector<string> >(contactPhoneNumber, tempVector));
    rewriteFile(adressList);
}

void changePhoneNumber(map<string, vector<string> > &adressList, string contactPhoneNumber) {
    auto tempVector = adressList[contactPhoneNumber];
    adressList.erase(contactPhoneNumber);
    string tempNumber;
    cout << "Enter new phone number: ";
    cin >> tempNumber;
    adressList.insert(pair<string, vector<string> >(tempNumber, tempVector));
    rewriteFile(adressList);
}

void changeCity(map<string, vector<string> > &adressList, string contactPhoneNumber) {
    auto tempVector = adressList[contactPhoneNumber];
    adressList.erase(contactPhoneNumber);
    string tempCity;
    cout << "Enter new city: ";
    cin >> tempCity;
    tempVector[1] = tempCity;
    adressList.insert(pair<string, vector<string> >(contactPhoneNumber, tempVector));
    rewriteFile(adressList);
}

void deleteItem(map<string, vector<string> > &adressList, string contactPhoneNumber, int &num) {
    adressList.erase(contactPhoneNumber);
    num--;
    rewriteFile(adressList);
}

void changeModule(map<string, vector<string> > &adressList, string contactPhoneNumber, int &num) {
    auto tempVector = adressList[contactPhoneNumber];
    cout << "--------------------------------------------------------------------" << endl;
    cout << "| Name                 | Phone              | City                 |" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "| " << tempVector[0];
    for(int k = 0; k<(21-tempVector[0].length()); k++) {
        cout << " ";
    }
    cout << "| " << contactPhoneNumber;
    for(int k = 0; k<(19-contactPhoneNumber.length()); k++) {
        cout << " ";
    }
    cout << "| " << tempVector[1];
    for(int k = 0; k<(21-tempVector[1].length()); k++) {
        cout << " ";
    }
    cout << "|" << endl;
    cout << "---------------------------CHOOSE ACTION----------------------------" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "| 1.Ch. name | 2. Ch. number | 3. Ch. city | 4. Delete | 5. Cancel |" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Enter number of menu item: ";
    int menuItem = 0;
    cin >> menuItem;
    switch (menuItem) {
        case 1:
            changeName(adressList, contactPhoneNumber);
            break;
        case 2:
            changePhoneNumber(adressList, contactPhoneNumber);
            break;
        case 3:
            changeCity(adressList, contactPhoneNumber);
            break;
        case 4:
            deleteItem(adressList, contactPhoneNumber, num);
            break;
        case 5:
            cout << "Cancel..." << endl;
            break;
        default:
            cout << "Unknow menu item." << endl;
            break;
    }
}

void showAll(map<string, vector<string> > &adressList, int &num) {
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
        cout << "Enter phone number of the contact to select it or enter ECS to back to main menu: ";
        string tempNumber;
        cin >> tempNumber;
        if (tempNumber != "Esc")
            changeModule(adressList, tempNumber, num);
    }
}

void addNew(map<string, vector<string> > &adressList, int &num, int &recInd, string &recPointer, int &recAmount, bool exitInd, vector<string> &recVector) {
    string tempName, tempNumber, tempCity;
    cout << "Enter name: ";
    cin >> tempName;
    cout << "Enter number: ";
    cin >> tempNumber;
    cout << "Enter city: ";
    cin >> tempCity;
    vector<string> tempVector(2);
    tempVector[0] = tempName;
    tempVector[1] = tempCity;
    adressList.insert(pair<string, vector<string> >(tempNumber, tempVector));
    num++;
    if(recInd == 0) {
        recPointer = tempNumber;
        recInd = 1;
    }
    recAmount++;
    recVector.push_back(tempNumber);
    SaveChanges(adressList, num, recInd, recPointer, recAmount, exitInd, recVector);
}

void searchName(map<string, vector<string> > adressList, int num) {
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

void searchNumber(map<string, vector<string> > adressList, int num) {
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

void searchCity(map<string, vector<string> > adressList, int num) {
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

void search(map<string, vector<string> > adressList, int num) {
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
    map<string, vector<string> > adressList;
    
    int num = 0, recInd = 0, recAmount = 0;
    string recPointer = "";
    bool exitInd = false;
    vector<string> recVector;
    
    string tempName, tempNumber, tempCity;
    
    /*ofstream fout("adressBookCPP.txt");           // Create file
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
            adressList.insert(pair<string, vector<string> >(tempNumber, tempVector));
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
        
        int menuItem;
        cin >> menuItem;
        
        switch(menuItem) {
            case 1:
                showAll(adressList, num);       //Show all contacts from real time memory
                break;
            case 2:
                addNew(adressList, num, recInd, recPointer, recAmount, exitInd, recVector);     //Add new contact
                break;
            case 3:
                search(adressList, num);        //Search contacts
                break;
            case 4:
                exitInd = true;     //Exit program
                SaveChanges(adressList, num, recInd, recPointer, recAmount, exitInd, recVector);
                ind = false;
                break;
            default:
                cout << "Unknow menu item!" << endl;
                break;
        }
    }
}