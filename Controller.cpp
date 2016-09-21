//
//  main.cpp
//  AdressBookBeta2
//
//  Created by victor on 21/09/2016.
//  Copyright © 2016 victor. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <sstream>
#include <fstream>

#include "Model.h"
#include "View.h"

int main() {
    AdressBook adressBook;
    View view(&adressBook);
    
    adressBook.loadFromFile();
    bool showMenu = true;
    while(showMenu) {
        int menuItem;
        menuItem = view.mainMenu();
        switch(menuItem) {
            //MARK: SHOW ALL CONTACTS FROM REAL TIME MEMORY
            case 1: {
                int numberInTheList = view.showAll();
                if (numberInTheList != 100500 && (numberInTheList > 0 && numberInTheList < adressBook.getSize())) {
                    int changeMenuItem = view.changeModuleMenu();
                    if (changeMenuItem > 0 && changeMenuItem < 4) {
                        string newValue = view.enterChangeValue(changeMenuItem);
                        adressBook.changeModuleCommutator(changeMenuItem, numberInTheList-1, newValue);
                    }
                    else if(changeMenuItem == 4) adressBook.remove(numberInTheList);
                }
                break;
            }
            //MARK: ADD NEW CONTACT
            case 2: {
                adressBook.addNew(view.addNewViewController());
                break;
            }
            //MARK: SEARCH CONTACTS
            case 3: {
                int searchMenuItem = view.menuSearch();
                if (searchMenuItem != -1) {
                    string keyWord = view.searchKeyWordEnter(searchMenuItem);
                    view.showSearchResults(adressBook.searchCommutator(keyWord, searchMenuItem));
                }
                break;
            }
            //MARK: EXIT PROGRAM
            case 4:
                showMenu = false;
                break;
            default:
                cout << "Unknow menu item!" << endl;
                break;
        }
    }
}
