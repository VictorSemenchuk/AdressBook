//
//  Contact.h
//  AdressBookBeta
//
//  Created by victor on 20/09/16.
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

