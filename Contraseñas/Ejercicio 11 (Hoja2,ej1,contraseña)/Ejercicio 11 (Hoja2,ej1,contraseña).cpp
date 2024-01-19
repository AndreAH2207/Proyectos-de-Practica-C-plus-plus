#include "pch.h"
#include "Pasword.hpp"
#include <iostream>

using namespace std;
using namespace System;

int main() {
    CPassword* password = NULL;
    CPassword* isSecure();

    int randomLenght;
    srand(time(0));
    randomLenght = (rand() % 32) + 8;
    
    password = new CPassword(randomLenght);

    cout << "Password : " << password->getPassword() << endl;
    cout << "Length   : " << password->getLength() << endl;
    cout << "Secure   : " << password->isSecure() << endl;
                            
    delete password;

    return 0;
}

