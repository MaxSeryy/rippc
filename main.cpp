#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
using namespace std;

void menu() {
    cout << "\n^-^ R.I.P. YOUR PC ^-^" << endl;
    cout << "1. Test your PC" << endl;
    cout << "2. How much free PHYSICAL memory" << endl;
    cout << "3. Exit" << endl;
}

int freeMemory() {
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);
    GlobalMemoryStatusEx(&statex);
    cout << "There is " << statex.ullAvailPhys / 1024 / 1024 << " MB of PHYSICAL memory available." << endl;
    return 0;
}

int test() {
    int *arr;
    double p = 3.141592653589793238462643;
    double pi = 3.141592653589793238462643;

    while (true) {
        arr = new int[1000000];
        for (int i = 0; i < 1000000; i++) {
            arr[i] = i;
            if (arr[i] % static_cast<int>(p * pi) == 0) {
                arr[i] = arr[i] / static_cast<int>(p);
            }
        }
    }
    return 0;
}

int main() {
    int choice;
    do {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Test" << endl;
                test();
                break;
            case 2:
                cout << "Free Memory" << endl;
                freeMemory();
                break;
            case 3:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 3);
    return 0;
}