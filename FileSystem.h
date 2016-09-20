//
//  FileSystem.h
//  AdressBookBeta
//
//  Created by victor on 20/09/16.
//  Copyright © 2016 victor. All rights reserved.
//

class FileSystem {
    vector<Contact> contactList;
public:
    //MARK: GET PARAMETERS
    vector<Contact> get() {
        return contactList;
    }
    
    //MARK: SET PARAMETERS
    void set(vector<Contact> contactList) {
        this->contactList = contactList;
    }
    
    //MARK: LOAD DATE FROM THE FILE
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
                //amount++;
            }
        }
        sourceFile.close();
    }
    
    //MARK: SAVE CHANGES IN THE FILE
    void saveChanges() {
        ofstream sourceFile("adressBookCPP.txt", ios_base::app);
        int counter = 0;
        while(counter < contactList.size()) {
            sourceFile << contactList[counter].getName() << " " << contactList[counter].getPhoneNumber() << " " << contactList[counter].getCity() << endl;
            counter++;
        }
        sourceFile.close();
    }
};

