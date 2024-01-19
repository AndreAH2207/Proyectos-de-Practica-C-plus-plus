#include "pch.h"
#include <iostream>

using namespace std;

int randomRange(int min, int max) {
    return (rand() % (max - min + 1)) + min; //genera números al azar
}

void sortArray(int array[], int size) { 
    int i, j, temp;

    // bubble sort algorithm
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (array[j] > array[i]) {
                temp = array[i];          //orden descendiente
                array[i] = array[j];
                array[j] = temp;   
            }
        }
    }
}

void fillArray(int array[], int size) {
    for (int index = 0; index < size; index++) {
        array[index] = randomRange(10, 99); //estabece rango y límite total de números
    }
}

void showArray(int array[], int size) {
    for (int index = 0; index < size; index++) { 
        cout << array[index] << " "; //lista números

        if ((index + 1) % 10 == 0) //salta de linea cada 10 números listados
            cout << endl;
    }
    cout << endl;
}

int test_StaticArray() {
    int array[100];
    int arraySize = sizeof(array) / sizeof(array[0]);

    fillArray(array, arraySize);
    showArray(array, arraySize);          

    sortArray(array, arraySize);
    showArray(array, arraySize);

    return 0;
}

int test_DynamicArray() {
    int* array = NULL;
    int arraySize = 100;

    array = new int[arraySize];

    fillArray(array, arraySize);
    showArray(array, arraySize);

    sortArray(array, arraySize);
    showArray(array, arraySize);

    delete[] array;

    return 0;
}

int drawMenu(const char* title, const char* items[]) {
    int index, choice, max;

    cout << "*** " << title << " ***" << endl;

    index = 0;
    while (items[index] != NULL) {
        cout << "[" << index + 1 << "] " << items[index] << endl;
        index++;
    }
    max = index;

    cout << endl << "Select your choice: ";
    cin >> choice;
    cout << endl;

    if (choice == 0 || choice > max) {
        return -1;
    }

    return choice;
}

void searchMinorAndPos(int array[], int arraySize, int* minor, int* position) {
    int index;
    int minNumberVal;
    int minNumberPos;

    minNumberVal = array[0];
    minNumberPos = 0;

    for (index = 1; index < arraySize; index++) {
        if (array[index] < minNumberVal) {
            minNumberVal = array[index];
            minNumberPos = index;
        }
    }

    *minor = minNumberVal;
    *position = minNumberPos + 1;
}

void searchMajorAndPos(int array[], int arraySize, int* major, int* position) {
    int index;
    int maxNumberVal;
    int maxNumberPos;
        
    maxNumberVal = array[0];
    maxNumberPos = 0;

    for (index = 1; index < arraySize; index++) {
        if (array[index] > maxNumberVal) {
            maxNumberVal = array[index];
            maxNumberPos = index;
        }
    }

    *major = maxNumberVal;
    *position = maxNumberPos + 1;
}

int main() {
    const char* items[] = { "Generate", "List", "Major", "Minor", "Sort", "Exit", NULL };
    int* array;
    int arraySize, choice, major, minor, position;

    // create dynamic array
    arraySize = 100;
    array = new int[arraySize];

    while (1) {
        choice = drawMenu((const char*)"ARRAY DEMO", items);

        if (choice == 6) {
            cout << "> Exit program" << endl << endl;
            break;
        }

        switch (choice) {
        case 1:
            cout << "> Generate" << endl;
            fillArray(array, arraySize);
            cout << "> " << arraySize << " random numbers has been generated." << endl << endl;
            break;

        case 2:
            cout << "> List" << endl;
            showArray(array, arraySize);
            cout << "> " << arraySize << " numbers." << endl << endl;
            break;

        case 3:
            cout << "> Major" << endl;
            searchMajorAndPos(array, arraySize, &major, &position);
            cout << "> The major number is " << major << ", in the position " << position << endl << endl;
            break;

        case 4:
            cout << "> Minor" << endl;
            searchMinorAndPos(array, arraySize, &minor, &position);
            cout << "> The minor number is " << minor << ", in the position " << position << endl << endl;
            break;

        case 5:
            cout << "> Sort" << endl;
            sortArray(array, arraySize);
            showArray(array, arraySize);
            cout << "> " << arraySize << " numbers sorted." << endl << endl;
            break;

        default:
            cout << ">>> Invalid option <<<" << endl << endl;
        }
    }

    // destroy dynamic array
    delete[] array;

    return 0;
}