//
//  Contact.h
//  AdressBookBeta2
//
//  Created by victor on 21/09/2016.
//  Copyright © 2016 victor. All rights reserved.
//

using namespace std;

class Contact {
    string name, phoneNumber, city;
public:
    
    //MARK: CONSTRUCTORS
    Contact(string name, string phoneNumber, string city) {
        this->name = name;
        this->phoneNumber = phoneNumber;
        this->city = city;
    }
    
    //MARK: SET PARAMETERS
    void setName(string name) {
        this->name = name;
    }
    void setPhoneNumber(string phoneNumber) {
        this->phoneNumber = phoneNumber;
    }
    void setCity(string city) {
        this->city = city;
    }
    
    //MARK: GET PARAMETERS
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
    int amount = 0;
public:
    vector<Contact> getContactList() {
        return contactList;
    }
    
    int getSize() {
        return contactList.size();
    }
    
    //MARK: CHANGE MODULE
    void changeModuleCommutator(int menuItem, int numberInList, string newParameter) {
        switch(menuItem) {
            case 1:
                changeName(numberInList, newParameter);
                break;
            case 2:
                changePhoneNumber(numberInList, newParameter);
                break;
            case 3:
                changeCity(numberInList, newParameter);
                break;
        }
    }
    
    void changeName(int iterNumber, string name) {
        contactList[iterNumber].setName(name);
        rewriteFile();
    }
    void changePhoneNumber(int iterNumber, string phoneNumber) {
        contactList[iterNumber].setPhoneNumber(phoneNumber);
        rewriteFile();
    }
    void changeCity(int iterNumber, string city) {
        contactList[iterNumber].setCity(city);
        rewriteFile();
    }
    void remove(int iterNumber) {
        contactList.erase(contactList.begin()+iterNumber-1);
        rewriteFile();
    }
    
    //MARK: SEARCH
    vector<int> searchCommutator(string keyWord, int menuItem) {
        vector<int> tempVector;
        int counter = 0;
        switch (menuItem) {
            case 1: {
                while(counter < contactList.size()) {
                    if(keyWord == contactList[counter].getName()) {
                        tempVector.push_back(counter);
                    };
                    counter++;
                }
                break;
            }
            case 2: {
                while(counter < contactList.size()) {
                    if(keyWord == contactList[counter].getPhoneNumber()) {
                        tempVector.push_back(counter);
                    };
                    counter++;
                }
                break;
            }
            case 3: {
                while(counter < contactList.size()) {
                    if(keyWord == contactList[counter].getCity()) {
                        tempVector.push_back(counter);
                    };
                    counter++;
                }
                break;
            }
        }
        return tempVector;
    }
    
    //MARK: ADD NEW CONTACT
    void addNew(Contact newContact) {
        contactList.push_back(newContact);
        saveChanges();
    }
    void addNew(string name, string phoneNumber, string city) {
        Contact newContact(name, phoneNumber, city);
        contactList.push_back(newContact);
        saveChanges();
    }
    
    //MARK: FILE SYSTEM
    void loadFromFile() {
        //CREATE FILE
        /*ofstream fout("adressBookCPP.txt");
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
    
    void saveChanges() {
        //cout << "SAVE CHANGES..." << endl;
        ofstream sourceFile("adressBookCPP.txt", ios_base::app);
        if (amount == 0)
            sourceFile << contactList[contactList.size()-1].getName() << " " << contactList[contactList.size()-1].getPhoneNumber() << " " << contactList[contactList.size()-1].getCity();
        else
            sourceFile << endl << contactList[contactList.size()-1].getName() << " " << contactList[contactList.size()-1].getPhoneNumber() << " " << contactList[contactList.size()-1].getCity();
        amount++;
        sourceFile.close();
    }
    
    void rewriteFile() {
        int amount = 0;
        ofstream sourceFile("adressBookCPP.txt");
        while (amount < contactList.size()) {
            if(amount == 0)
                sourceFile << contactList[amount].getName() << " " << contactList[amount].getPhoneNumber() << " " << contactList[amount].getCity();
            else
                sourceFile << endl << contactList[amount].getName() << " " << contactList[amount].getPhoneNumber() << " " << contactList[amount].getCity();
    
            amount++;
        }
        sourceFile.close();
    }
};
