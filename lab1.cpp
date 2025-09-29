#include <iostream>

using namespace std;

int main() {

    // 1
    int i;

    // 2
    i = 69;

    // 3
    int number = 72;

    // 4
    i = i + number;

    // 5
    int arr[3] = {0, 0, 0};

    // 6
    int* iPointer = &i;

    // 7
    number = *iPointer;

    // 8
    *iPointer = 15;

    // 9
    iPointer = &arr[0];

    // 10
    iPointer = iPointer + 2;

    // 11
    arr[0] = 5;
    *iPointer = 6;

    cout << "i = " << i << endl;
    cout << "number = " << number << endl;
    cout << "arr[0] = " << arr[0] << endl;
    cout << "arr[1] = " << arr[1] << endl;
    cout << "arr[2] = " << arr[2] << endl;

    return 0;
}
