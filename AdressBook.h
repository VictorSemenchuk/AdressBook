//
//  AdressBook.h
//  AdressBookBeta
//
//  Created by victor on 20/09/16.
//  Copyright © 2016 victor. All rights reserved.
//

class AdressBook {
    vector<Contact> *contactList;
    //int recInd, recAmount, amount, recPointer;
    //bool exitInd;
public:
    //MARK: CONSTRUCTORS
    AdressBook(vector<Contact> *contactList) {
        /*recInd = 0;
        recPointer = 0;
        recAmount = 0;
        amount = 0;
        exitInd = false;*/
        this->contactList = contactList;
    }
    
    //MARK: CHANGE MODULE
    void changeName(int iterNumber, string name) {
        (*contactList)[iterNumber].setName(name);
    }
    void changePhoneNumber(int iterNumber, string phoneNumber) {
        (*contactList)[iterNumber].setPhoneNumber(phoneNumber);
    }
    void changeCity(int iterNumber, string city) {
        (*contactList)[iterNumber].setCity(city);
    }
    void remove(int iterNumber) {
        (*contactList).erase((*contactList).begin()+iterNumber);
    }
    
    //MARK: SEARCH
    int searchPhoneNumber(string phoneNumber) {
        int counter = 0;
        while(counter < (*contactList).size()) {
            if(phoneNumber == (*contactList)[counter].getPhoneNumber()) {
                return counter;
            };
            counter++;
        }
        return -1;
    }
    vector<int> searchName(string name) {
        vector<int> tempVector;
        int counter = 0;
        while(counter < (*contactList).size()) {
            if(name == (*contactList)[counter].getName()) {
                tempVector.push_back(counter);
            };
            counter++;
        }
        return tempVector;
    }
    vector<int> searchCity(string city) {
        vector<int> tempVector;
        int counter = 0;
        while(counter < (*contactList).size()) {
            if(city == (*contactList)[counter].getCity()) {
                tempVector.push_back(counter);
            };
            counter++;
        }
        return tempVector;
    }
    
    //MARK: ADD NEW CONTACT
    void addNew(Contact newContact) {
        (*contactList).push_back(newContact);
    }
    void addNew(string name, string phoneNumber, string city) {
        Contact newContact(name, phoneNumber, city);
        (*contactList).push_back(newContact);
        /*if(recInd == 0) {
         recPointer = amount;
         recInd = 1;
         }
         amount++;
         recAmount++;*/
        //saveChanges();
    }
};

