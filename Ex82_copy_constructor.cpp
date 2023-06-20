#include <iostream>
#include <string>
using namespace std;

/*
*    Конструктор копирования
*/

class MyClass {  
public:
    int data;
    MyClass(int data) {
        this->data = data;
        cout << "Вызвался конструктор " << this << endl;
    }
    ~MyClass() {
        cout << "Вызвался деструктор " << this << endl;
    }
};

void Foo(MyClass value) { // функция в которой вызывается конструктор копирования
    cout << "Вызвалась функция Foo" << endl;
}

MyClass Foo2() { // функция в которой вызывается конструктор копирования
    cout << "Вызвалась функция Foo_2" << endl;
    MyClass temp(2);
    return temp;
}

class MyClass2 {  
public:
    int *data;
    MyClass2(int size) {
        this->Size = size;
        this->data = new int[size]; // создаем массив
        for(int i = 0; i < size; i++) { // заполняем его итератором (от нуля до размера)
            data[i] = i;
        }
        cout << "Вызвался конструктор " << this << endl;
    }
    ~MyClass2() {
        cout << "Вызвался деструктор " << this << endl;
        delete[] data; // освобождаем память выделенную под массив
    }
    // MyClass2(const MyClass2 &other) { // конструктор копирования по умолчанию
    //     this->data = other.data; // здесь мы присваили одну и ту же ссылку для копируемого объекта и текущего
    //     cout << "Вызвался конструктор копирования " << this << endl;
    // }
    MyClass2(const MyClass2 &other) { // конструктор копирования правильный
        this->Size = other.Size; // копируем значение размера массива
        this->data = new int[other.Size];
        // в новом объекте мы создаем новый объект размера количества ячеек в первом объекте
        for(int i = 0; i < other.Size; i++) { // заполняем его итератором (от нуля до размера)
            this->data[i] = other.data[i];
        }
        // после этого нам нужно пробежаться по ячеек нового объекта и скопировать старые ячейки
        cout << "Вызвался конструктор копирования " << this << endl;
    }
    int Size; // размер массива
};
// при создании объекта класса мы передаем параметр, который будет отвечать за кол-во элементов в массиве
// который мы создаем в динамической памяти

// конструктор копирования принимает константный параметр типа MyClass2
// параметр константный потому что ничего в этом объекте мы менять не будем
// other (другой) обратный this (этот), мы other копируем в this

int main() {
    // MyClass a(1);
    // 3 случая когда используется конструктор копирования
    // Foo(a); // функция в которой вызывается конструктор копирования 
    // Foo2(); // функция в которой вызывается конструктор копирования
    // MyClass b(a); // создаем объект а на основе объекта b (снова копию объекта создаем)

    MyClass2 a(1);
    MyClass2 b(a); 
      
    return 0; 
}

// если не описать конструктор копирования, компилятор создаст его по умолчанию
// но этот конструктор может работать не так как нам нужно

// создадим функцию Foo, которая принимает на вход объект класса MyClass
// когда мы вызываем функцию Foo переданный объект копируется и деструктор вызывается 2 раза
// для основного объекта и для скопированного объекта
// в классе есть реализованный по умолчанию конструктор копирования, 
// в результате мы получаем точную копию объекта переданного объекта в функцию Foo

// теперь опишем случай в котором конструктор по умолчанию нам не подходит
// создадим новый класс в котором используется динамическая память
// в нем в деструкторе мы освобождаем память под динамический массив
// при запуске такой программы мы получаем ошибку
// это происходит потому что здесь копирование указателя на массив, но сам массив не копируется
// в итоге мы получаем 2 указателя, которые ссылаются на один и тот же массив
// деструктор вызывается для каждого класса и при втором вызове мы пытаемся освободить уже освободенную память

// чтобы выйти из этой ситуации нам нужно написать свой конструктор копирования
