#include <string.h>
#include <iostream>

struct TwoInts
{
    int a;
    int b;
};

struct StructWithArray
{
    int arr[4];
    int* someNumber;
};

int main()
{
    // инициализация
    TwoInts i2 = { };
    i2.a = 5; // 5 в i2.a
    i2.b = 7; // 7 в i2.b

    // вывод:
    // 5
    std::cout << i2.a << std::endl;
    // 7
    std::cout << i2.b << std::endl;

    StructWithArray s = { };
    s.arr[0] = 10; // s.arr = {10,0,0,0}

    StructWithArray s1 = { };
    s1.arr[0] = 15; // s1.arr = {15,0,0,0}

    // указатель на структуру s
    StructWithArray* sPointer = &s;
    sPointer->arr[0] = 20; // s.arr[0] = 20

    // вывод:
    // s.arr[0] = 20
    std::cout << s.arr[0] << std::endl;

    s.arr[0] = 25; // 25 в s.arr[0]
    // вывод:
    // 25
    std::cout << s.arr[0] << std::endl;

    // sPointer указывает на s, поэтому изменит s
    sPointer->arr[0] = 30; // s.arr[0] = 30
    // вывод:
    // 30
    std::cout << s.arr[0] << std::endl;

    // указатель на s1
    sPointer = &s1;
    sPointer->arr[0] = 35; // s1.arr[0] = 35

    // вывод:
    // 30
    std::cout << s.arr[0] << std::endl;
    // вывод:
    // 35
    std::cout << s1.arr[0] << std::endl;

    // массив из 2 структур
    StructWithArray structArray[2] = { };
    structArray[0].arr[3] = 77;
    // указатель arr[3]
    structArray[1].someNumber = &structArray[0].arr[3];

    // sPointer снова на s
    sPointer = &s;
    // адрес элемента arr[3]
    int* pointer = &sPointer->arr[3];

    // менчем s.arr[3]
    s.arr[3] = 72;
    // вывод: 
    // 72
    std::cout << *pointer;

    // весь вывод:
    // 5
    // 7
    // 20
    // 25
    // 30
    // 30
    // 35
    // 72

    StructWithArray memory;
    memset(&memory, 0, sizeof(StructWithArray));

    return 0;
}
