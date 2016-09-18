//
//  main.cpp
//  AdressBook
//
//  Created by victor on 13/09/16.
//  Copyright © 2016 victor. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class Contact {
    string name, phoneNumber, city;
public:
    
    //CONSTRUCTORS
    Contact(string name, string phoneNumber, string city) {
        this->name = name;
        this->phoneNumber = phoneNumber;
        this->city = city;
    }
    
    //SET PARAMETERS
    void setName(string name) {
        this->name = name;
    }
    void setPhoneNumber(string phoneNumber) {
        this->phoneNumber = phoneNumber;
    }
    void setCity(string city) {
        this->city = city;
    }
    
    //GET PARAMETERS
    string getName() {
        return name;
    }
    string getPhoneNumber() {
        return phoneNumber;
    }
    string getCity() {
        return city;
    }
};

class AdressBook {
    vector<Contact> contactList;
    int recInd, recAmount, amount, recPointer;
    bool exitInd;
public:
    
    //CONSTRUCTORS
    AdressBook() {
        recInd = 0;
        recPointer = 0;
        recAmount = 0;
        amount = 0;
        exitInd = false;
    }
    
    //EXIT PROGRAM
    void exitProg() {
        exitInd = true;
        saveChanges();
    }
    
    //LOAD DATE FROM THE FILE
    void loadFromFile() {
        /*ofstream fout("adressBookCPP.txt");           //CREATE FILE
         fout.close();*/
        
        string tempName, tempNumber, tempCity;
        ifstream sourceFile("adressBookCPP.txt", ios_base::in);
        
        while(!sourceFile.eof()) {
            sourceFile >> tempName;
            if (tempName != "") {
                sourceFile >> tempNumber;
                sourceFile >> tempCity;
                Contact newContact(tempName, tempNumber, tempCity);
                contactList.push_back(newContact);
                amount++;
            }
        }
        
        sourceFile.close();
    }
    
    //SAVE CHANGES IN THE FILE
    void saveChanges() {
        if ((exitInd == false && recAmount % 2 == 0 && recInd == 1) || ((exitInd == true) && (recInd == 1) && ((recAmount % 2 == 0) || (recAmount % 2 != 0)))) {
            cout << "SAVE CHANGES..." << endl;
            ofstream sourceFile("adressBookCPP.txt", ios_base::app);
            int counter = recPointer;
            while(counter < amount) {
                if(amount == 0)
                    sourceFile << contactList[counter].getName() << " " << contactList[counter].getPhoneNumber() << " " << contactList[counter].getCity();
                else
                    sourceFile << endl << contactList[counter].getName() << " " << contactList[counter].getPhoneNumber() << " " << contactList[counter].getCity();
                counter++;
            }
            sourceFile.close();
            recInd = 0;
            recAmount = 0;
        }
    }
    
    //REWRITE THE FILE
    void rewriteFile() {
        amount = 0;
        ofstream sourceFile("adressBookCPP.txt");
        while (amount < contactList.size()) {
            if(amount == 0)
                sourceFile << contactList[amount].getName() << " " << contactList[amount].getPhoneNumber() << " " << contactList[amount].getCity();
            else
                sourceFile << endl << contactList[amount].getName() << " " << contactList[amount].getPhoneNumber() << " " << contactList[amount].getCity();
            amount++;        }
        sourceFile.close();
    }
    
    //CHANGE MODULE
    void changeModule(int contactNumber) {
        cout << "--------------------------------------------------------------------" << endl;
        cout << "| Name                 | Phone              | City                 |" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "| " << contactList[contactNumber].getName();
        for(int k = 0; k<(21-contactList[contactNumber].getName().length()); k++) {
            cout << " ";
        }
        cout << "| " << contactList[contactNumber].getPhoneNumber();
        for(int k = 0; k<(19-contactList[contactNumber].getPhoneNumber().length()); k++) {
            cout << " ";
        }
        cout << "| " << contactList[contactNumber].getCity();
        for(int k = 0; k<(21-contactList[contactNumber].getCity().length()); k++) {
            cout << " ";
        }
        cout << "|" << endl;
        cout << "---------------------------CHOOSE ACTION----------------------------" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "| 1.Ch. name | 2. Ch. number | 3. Ch. city | 4. Delete | 5. Cancel |" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "Enter number of menu item: ";
        
        int menuItem;
        cin >> menuItem;
        switch(menuItem) {
            case 1:
                cout << "Enter new NAME: ";
                break;
            case 2:
                cout << "Enter new PHONE NUMBER: ";
                break;
            case 3:
                cout << "Enter new CITY: ";
                break;
            case 4:
                break;
            case 5:
                break;
        }
        if (menuItem > 0 && menuItem < 4) {
            string newWord;
            cin >> newWord;
            switch (menuItem) {
                case 1:
                    contactList[contactNumber].setName(newWord);
                    break;
                case 2:
                    contactList[contactNumber].setPhoneNumber(newWord);
                    break;
                case 3:
                    contactList[contactNumber].setCity(newWord);
                    break;
            }
        }
        if (menuItem == 4) {
            contactList.erase(contactList.begin()+contactNumber);
            amount--;
        }
        if(menuItem > 0 && menuItem <= 4) {
            rewriteFile();
        }
    }
    
    //SHOW ALL CONTACTS
    void showAll() {
        if(contactList.size() == 0)
            cout << "Sorry, your contact list is empty!" << endl;
        else {
            int counter = 0, amount = 0;
            cout << "--------------------------------------------------------------------" << endl;
            cout << "| Name                 | Phone              | City                 |" << endl;
            cout << "--------------------------------------------------------------------" << endl;
            while(counter < contactList.size()) {
                ostringstream out;
                out << ++amount;
                string numberStr = out.str();
                cout << "| " << numberStr << ". " << contactList[counter].getName();
                for(int k = 0; k<(21-numberStr.length() - 2 - contactList[counter].getName().length()); k++) {
                    cout << " ";
                }
                cout << "| " << contactList[counter].getPhoneNumber();
                for(int k = 0; k<(19-contactList[counter].getPhoneNumber().length()); k++) {
                    cout << " ";
                }
                cout << "| " << contactList[counter].getCity();
                for(int k = 0; k<(21-contactList[counter].getCity().length()); k++) {
                    cout << " ";
                }
                cout << "|" << endl;
                counter++;
            }
            cout << "--------------------------------------------------------------------" << endl;
            cout << "Enter number of the contact to select it or enter 100500 to back \nto main menu: ";
            int tempNumber;
            cin >> tempNumber;
            if (tempNumber != 100500)
                changeModule(tempNumber-1);
        }
    }
    
    //SEARCH
    void search() {
        if(contactList.size() == 0)
            cout << "Sorry, your contact list is empty!" << endl;
        else {
            cout << "-------------------------------SEARCH-------------------------------" << endl;
            cout << "--------------------------------------------------------------------" << endl;
            cout << "|    1. Name      | 2. Phone number  |    3. City    |  4. Cancel  |" << endl;
            cout << "--------------------------------------------------------------------" << endl;
            cout << "Enter number of menu item: ";
            
            int menuItem;
            cin >> menuItem;
            
            switch(menuItem) {
                case 1:
                    cout << "Enter name: ";
                    break;
                case 2:
                    cout << "Enter phone number: ";
                    break;
                case 3:
                    cout << "Enter city: ";
                    break;
                case 4:
                    break;
                default:
                    cout << "Unknow menu item!" << endl;
                    break;
            }
            
            if (menuItem < 4 && menuItem > 0) {
                string keyWord;
                cin >> keyWord;
                int counter = 0;
                bool findInd = false;
                string compareWord;
                int amount = 0;
                while(counter < contactList.size()) {
                    switch(menuItem) {
                        case 1:
                            compareWord = contactList[counter].getName();
                            break;
                        case 2:
                            compareWord = contactList[counter].getPhoneNumber();
                            break;
                        case 3:
                            compareWord = contactList[counter].getCity();
                            break;
                    }
                    if (keyWord == compareWord) {
                        if(!findInd) {
                            cout << "--------------------------------------------------------------------" << endl;
                            cout << "| Name                 | Phone              | City                 |" << endl;
                            cout << "--------------------------------------------------------------------" << endl;
                        }
                        ostringstream out;
                        out << ++amount;
                        string numberStr = out.str();
                        cout << "| " << numberStr << ". " << contactList[counter].getName();
                        for(int k = 0; k<(21-numberStr.length() - 2 - contactList[counter].getName().length()); k++) {
                            cout << " ";
                        }
                        cout << "| " << contactList[counter].getPhoneNumber();
                        for(int k = 0; k<(19-contactList[counter].getPhoneNumber().length()); k++) {
                            cout << " ";
                        }
                        cout << "| " << contactList[counter].getCity();
                        for(int k = 0; k<(21-contactList[counter].getCity().length()); k++) {
                            cout << " ";
                        }
                        cout << "|" << endl;
                        findInd = true;
                    }
                    counter++;
                }
                cout << "--------------------------------------------------------------------" << endl;
                if(!findInd) {
                    switch(menuItem) {
                        case 1:
                            cout << "Sorry. We could not find any contact with name " << keyWord << "." << endl;
                            break;
                        case 2:
                            cout << "Sorry. We could not find any contact with phone number " << keyWord << "." << endl;
                            break;
                        case 3:
                            cout << "Sorry. We could not find any contact from " << keyWord << "." << endl;
                            break;
                    }
                }
                if(findInd) {
                    if(amount == 1)
                        cout << "Found " << amount << " contact." << endl;
                    else if (amount > 1)
                        cout << "Found " << amount << " contacts." << endl;
                }
                cout << ("Search completed!") << endl;
            }
        }
    }
    
    //ADD NEW CONTACT
    void addNew() {
        string tempName, tempPhoneNumber, tempCity;
        cout << "Enter name: ";
        cin >> tempName;
        cout << "Enter phone number: ";
        cin >> tempPhoneNumber;
        cout << "Enter city: ";
        cin >> tempCity;
        Contact newContact(tempName, tempPhoneNumber, tempCity);
        contactList.push_back(newContact);
        if(recInd == 0) {
            recPointer = amount;
            recInd = 1;
        }
        amount++;
        recAmount++;
        saveChanges();
    }
};

int main() {
    AdressBook adressBook;
    
    adressBook.loadFromFile();  //LOAD DATE FROM THE FILE IN REAL TIME MEMORY
    
    bool showMenu = true;
    while(showMenu) {
        cout << "------------------------------CONTACTS------------------------------" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "|   1. Show all   |    2. Add new    |   3. Search   |   4. Exit   |" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "Enter number of menu item: ";
        
        int menuItem;
        cin >> menuItem;
        
        switch(menuItem) {
            case 1:
                adressBook.showAll();       //SHOW ALL CONTACTS FROM REAL TIME MEMORY
                break;
            case 2: {                       //ADD NEW CONTACT
                adressBook.addNew();
                break;
            }
            case 3:                         //SEARCH CONTACTS
                adressBook.search();
                break;
            case 4:                         //EXIT PROGRAM
                adressBook.exitProg();
                showMenu = false;
                break;
            default:
                cout << "Unknow menu item!" << endl;
                break;
        }
    }
}