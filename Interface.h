//
//  Interface.h
//  AdressBookBeta
//
//  Created by victor on 20/09/16.
//  Copyright © 2016 victor. All rights reserved.
//

using namespace std;

class Interface{
    vector<Contact> *contactList;
    AdressBook adressbook(vector<Contact> *contactList);
public:
    //MARK: CONSTRUCTORS
    Interface(vector<Contact> *contactList){
        this->contactList=contactList;
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
    
    //MARK: SEARCH MENU
    int menuSearch(){
        if(contactList.size() == 0)
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
    
    //MARK: SHOW ALL
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
        }
    }
};

