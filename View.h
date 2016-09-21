//
//  View.h
//  AdressBookBeta2
//
//  Created by victor on 21/09/2016.
//  Copyright © 2016 victor. All rights reserved.
//

class View {
    AdressBook *adressBook;
public:
    
    //MARK: CONSTRUCTORS
    View(AdressBook *adressBook) {
        this->adressBook = adressBook;
    }
    
    //MARK: MAIN MENU
    int mainMenu(){
        int menuItem;
        cout << "------------------------------CONTACTS------------------------------" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "|   1. Show all   |    2. Add new    |   3. Search   |   4. Exit   |" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "Enter number of menu item: ";
        cin >> menuItem;
        return menuItem;
    }
    
    //MARK: SHOW ALL CONTACTS
    int showAll() {
        vector<Contact> contactList = (*adressBook).getContactList();
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
            return tempNumber;
        }
        return 0;
    }
    
    //MARK: CHANGE MODULE
    int changeModuleMenu() {
        cout << "---------------------------CHOOSE ACTION----------------------------" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "| 1.Ch. name | 2. Ch. number | 3. Ch. city | 4. Delete | 5. Cancel |" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "Enter number of menu item: ";
        
        int menuItem;
        cin >> menuItem;
        return menuItem;

    }
    
    string enterChangeValue(int menuItem) {
        string newValue;
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
        }
        cin >> newValue;
        return newValue;
    }
    
    //MARK: SEARCH
    int menuSearch(){
        if((*adressBook).getContactList().size() == 0)
            cout << "Sorry, your contact list is empty!" << endl;
        else {
            int menuItem;
            cout << "-------------------------------SEARCH-------------------------------" << endl;
            cout << "--------------------------------------------------------------------" << endl;
            cout << "|    1. Name      | 2. Phone number  |    3. City    |  4. Cancel  |" << endl;
            cout << "--------------------------------------------------------------------" << endl;
            cout << "Enter number of menu item: ";
            cin >> menuItem;
            return menuItem;
        }
        return -1;
    }
    
    string searchKeyWordEnter(int menuItem) {
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
        string keyWord;
        cin >> keyWord;
        return keyWord;
    }
    
    void showSearchResults(vector<int> intVector) {
        if (intVector.size() == 0) {
            cout << "Sorry. We could not find any contact." << endl;
        } else {
            vector<Contact> contactList = (*adressBook).getContactList();
            int counter = 0, amount = 0;
            cout << "--------------------------------------------------------------------" << endl;
            cout << "| Name                 | Phone              | City                 |" << endl;
            cout << "--------------------------------------------------------------------" << endl;
            while(counter < intVector.size()) {
                ostringstream out;
                out << ++amount;
                string numberStr = out.str();
                cout << "| " << numberStr << ". " << contactList[intVector[counter]].getName();
                for(int k = 0; k<(21-numberStr.length() - 2 - contactList[intVector[counter]].getName().length()); k++) {
                    cout << " ";
                }
                cout << "| " << contactList[intVector[counter]].getPhoneNumber();
                for(int k = 0; k<(19-contactList[intVector[counter]].getPhoneNumber().length()); k++) {
                    cout << " ";
                }
                cout << "| " << contactList[intVector[counter]].getCity();
                for(int k = 0; k<(21-contactList[intVector[counter]].getCity().length()); k++) {
                    cout << " ";
                }
                cout << "|" << endl;
                counter++;
            }
            cout << "--------------------------------------------------------------------" << endl;
            if(amount != 0) {
                if(amount == 1)
                    cout << "Found " << amount << " contact." << endl;
                else if (amount > 1)
                    cout << "Found " << amount << " contacts." << endl;
            }
            cout << ("Search completed!") << endl;
        }
    }
    
    //MARK: ADD NEW CONTACT
    Contact addNewViewController() {
        string tempName, tempPhoneNumber, tempCity;
        cout << "Enter name: ";
        cin >> tempName;
        cout << "Enter phone number: ";
        cin >> tempPhoneNumber;
        cout << "Enter city: ";
        cin >> tempCity;
        Contact tempContact(tempName, tempPhoneNumber, tempCity);
        return tempContact;
    }
};
