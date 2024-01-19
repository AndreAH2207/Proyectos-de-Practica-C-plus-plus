#pragma once
#include <iostream>

using namespace std;

class CPassword {
private:
    string password;
    int length;

public:
    CPassword();
    CPassword(int lenght);

    bool isSecure();
    void generatePassword();
    string getPassword();
    int getLength();
    void setLength(int length);                         
};

CPassword::CPassword() {
    this->password;
    this->length = 8;
    generatePassword();
}

CPassword::CPassword(int length) {
    this->length = length;
    generatePassword();
}

void CPassword::generatePassword() {
    string values = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int valuesLength = values.length();
    string newPassword = "";

    srand(time(0));
    for (int index = 0  ; index < this->length; index++) {
        newPassword = newPassword + values[rand() % valuesLength];
    }

    this->password = newPassword;
}


bool CPassword::isSecure() {

    char element;
    int Mayus = 0;
    int Minus = 0;
    int Number = 0;

    for (int index = 0; index < this->length; index++)
    {
        element = this->password[index];

        if (element >= 'A' && element <= 'Z')
        {
            Mayus++;
        }
        else if (element >= 'a' && element <= 'z')
        {
            Minus++;
        }
        else if (element >= '0' && element <= '9')
        {
            Number++;
        }
    }

    if (Mayus >= 3 && Minus >= 2 && Number >= 6)
    {
        cout << "V " << endl;
    }
    else {
        cout << "F " << endl;;
    }
    return false;
}

string CPassword::getPassword() {
    return this->password;
}

int CPassword::getLength() {
    return this->length;
}

void CPassword::setLength(int length) {
    this->length = length;
}