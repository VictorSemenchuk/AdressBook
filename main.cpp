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

using namespace std;

class Adress {
    string name, number, city;
public:
    Adress() {
        name = "";
        number = "";
        city = "";
    }
    Adress(string name, string number, string city) {
        this->name = name;
        this->number = number;
        this->city = city;
    }
    
    string getName() {
        return name;
    }
    string getNumber() {
        return number;
    }
    string getCity() {
        return city;
    }
    
    void setName(string name) {
        this->name = name;
    }
    void setNumber(string number) {
        this->number = number;
    }
    void setCity(string city) {
        this->city = city;
    }
};

class List {
public:
    Adress human;
    List *next;
};

void showAll(List *currArray, int num) {
    if (num == 0) {
        cout << "Sorry, your contact list is empty!" << endl;
    } else {
        cout << "--------------------------------------------------------------------" << endl;
        cout << "| Name                 | Phone              | City                 |" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        for(int i = 0; i<num; i++) {
            cout << "| " << currArray->human.getName();
            for(int k = 0; k<(21-currArray->human.getName().length()); k++) {
                cout << " ";
            }
            cout << "| " << currArray->human.getNumber();
            for(int k = 0; k<(19-currArray->human.getNumber().length()); k++) {
                cout << " ";
            }
            cout << "| " << currArray->human.getCity();
            for(int k = 0; k<(21-currArray->human.getCity().length()); k++) {
                cout << " ";
            }
            cout << "|" << endl;
            currArray = currArray->next;
        }
        cout << "--------------------------------------------------------------------" << endl;
    }
}

void addNew(List *&head, int &num) {
    string tempName, tempNumber, tempCity;
    cout << "Enter name: ";
    cin >> tempName;
    cout << "Enter phone number: ";
    cin >> tempNumber;
    cout << "Enter city: ";
    cin >> tempCity;
    ofstream sourceFile("adressBookCPP.txt", ios_base::app);
    if(num == 0)
        sourceFile << tempName << " " << tempNumber << " " << tempCity;
    else
        sourceFile << endl << tempName << " " << tempNumber << " " << tempCity;
    sourceFile.close();
    head->human.setName(tempName);
    head->human.setNumber(tempNumber);
    head->human.setCity(tempCity);
    head->next = new List;
    head = head->next;
    num++;
}

void searchName(List *currArray, int num) {
    int amount = 0;
    cout << "Enter NAME: ";
    string tempName;
    cin >> tempName;
    for(int i = 0; i<num; i++) {
        if(currArray->human.getName() == tempName) {
            if (amount == 0) {
                cout << "--------------------------------------------------------------------" << endl;
                cout << "| Name                 | Phone              | City                 |" << endl;
                cout << "--------------------------------------------------------------------" << endl;
            }
            cout << "| " << currArray->human.getName();
            for(int k = 0; k<(21-currArray->human.getName().length()); k++) {
                cout << " ";
            }
            cout << "| " << currArray->human.getNumber();
            for(int k = 0; k<(19-currArray->human.getNumber().length()); k++) {
                cout << " ";
            }
            cout << "| " << currArray->human.getCity();
            for(int k = 0; k<(21-currArray->human.getCity().length()); k++) {
                cout << " ";
            }
            cout << "|" << endl;
            amount++;
        }
        currArray = currArray->next;
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

void searchNumber(List *currArray, int num) {
    int amount = 0;
    cout << "Enter NUMBER: ";
    string tempNumber;
    cin >> tempNumber;
    for(int i = 0; i<num; i++) {
        if(currArray->human.getNumber() == tempNumber) {
            if (amount == 0) {
                cout << "--------------------------------------------------------------------" << endl;
                cout << "| Name                 | Phone              | City                 |" << endl;
                cout << "--------------------------------------------------------------------" << endl;
            }
            cout << "| " << currArray->human.getName();
            for(int k = 0; k<(21-currArray->human.getName().length()); k++) {
                cout << " ";
            }
            cout << "| " << currArray->human.getNumber();
            for(int k = 0; k<(19-currArray->human.getNumber().length()); k++) {
                cout << " ";
            }
            cout << "| " << currArray->human.getCity();
            for(int k = 0; k<(21-currArray->human.getCity().length()); k++) {
                cout << " ";
            }
            cout << "|" << endl;
            amount++;
        }
        currArray = currArray->next;
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

void searchCity(List *currArray, int num) {
    int amount = 0;
    cout << "Enter CITY: ";
    string tempCity;
    cin >> tempCity;
    for(int i = 0; i<num; i++) {
        if(currArray->human.getCity() == tempCity) {
            if (amount == 0) {
                cout << "--------------------------------------------------------------------" << endl;
                cout << "| Name                 | Phone              | City                 |" << endl;
                cout << "--------------------------------------------------------------------" << endl;
            }
            cout << "| " << currArray->human.getName();
            for(int k = 0; k<(21-currArray->human.getName().length()); k++) {
                cout << " ";
            }
            cout << "| " << currArray->human.getNumber();
            for(int k = 0; k<(19-currArray->human.getNumber().length()); k++) {
                cout << " ";
            }
            cout << "| " << currArray->human.getCity();
            for(int k = 0; k<(21-currArray->human.getCity().length()); k++) {
                cout << " ";
            }
            cout << "|" << endl;
            amount++;
        }
        currArray = currArray->next;
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

void search(List *currArray, int num) {
    cout << "-------------------------------SEARCH-------------------------------" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "|       1. Name        |   2. Phone number  |       3. City        |" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Enter number of menu item: ";
    
    int menuItem;
    cin >> menuItem;
    
    switch(menuItem) {
        case 1:
            searchName(currArray, num);
            break;
        case 2:
            searchNumber(currArray, num);
            break;
        case 3:
            searchCity(currArray, num);
            break;
        default:
            cout << "Cancel...";
            break;
    }
}

int main() {
    string tempName, tempNumber, tempCity;
    
    List *currArray = new List, *top, *head;
    top = currArray;
    head = currArray;
    
    int num = 0;
    
    /*ofstream fout("adressBookCPP.txt"); // Create file
    fout.close();*/
    
    ifstream sourceFile("adressBookCPP.txt", ios_base::in);
    
    while(!sourceFile.eof()) {
        sourceFile >> tempName;
        if (tempName != "") {
            sourceFile >> tempNumber;
            sourceFile >> tempCity;
            currArray->human.setName(tempName);
            currArray->human.setNumber(tempNumber);
            currArray->human.setCity(tempCity);
            currArray->next = new List;
            currArray = currArray->next;
            head = currArray;
            num++;
        }
    }
    
    sourceFile.close();
    currArray = top;
    
    bool ind = true;
    
    while(ind) {
        cout << "------------------------------CONTACTS------------------------------" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "|      1. Show all     |     2. Add new     |      3. Search       |" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "Enter number of menu item: ";
        
        int menuItem;
        cin >> menuItem;
        
        switch(menuItem) {
            case 1:
                showAll(currArray, num);
                break;
            case 2:
                addNew(head, num);
                break;
                
            case 3:
                search(currArray, num);
                break;
            case 4:
                ind = false;
                break;
            default:
                cout << "Unknow menu item!" << endl;
        }
    }
}

