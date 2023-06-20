#include <iostream>
#include <string>
using namespace std;

/*
*    Перегрузка оператора присваивания
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
    //     this->data = other.data; // здесь мы присвоили одну и ту же ссылку для копируемого объекта и текущего
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
    MyClass2 &operator = (const MyClass2 &other) {
        cout << "Вызвался оператор = " << this << endl;
        this->Size = other.Size;  // нет данимаческой памяти, значит ничего чисть не нужно
        if (this->data != nullptr) { // на всякий случай сделаем проверку
            delete[] data;
        }
        // после очистки памяти можем выделить память и записать значения
        this->data = new int[other.Size];
        for(int i = 0; i < other.Size; i++) { 
            this->data[i] = other.data[i];
        }
        return *this;
    }
    // для перегрузки оператора используется ключевое слово operator
    // в качестве аргумента в конструктор подается объект к которому мы будем присваивать
    // нам подайдет такая же запись как в конструкторе копирования (const MyClass2 &other)

    // так как у нас объект уже создан под него уже выделилась динамическая память
    // прежде чем записать какие-либо данные нам сначала нужно освободить память
    // это абсолютно безопасно, ситуации при которой у нас объект не создан быть не можем
    // ситуации при которой мы освобождаем уже освобожденную память быть не можем

    // с такой сигнатурой void operator = (const MyClass2 &other) 
    // у нас не сработает запись g = h = i;
    // чтобы она сработала нужно возвращать ссылку на объект MyClass2
    // вот так: MyClass2 &operator = (const MyClass2 &other)
    // и добавить return *this;
    int Size; // размер массива
};

int main() {
    MyClass2 a(1);
    MyClass2 b(a);
    a = b;
    // для компилятора запись a = b;
    // выглядит как запись a.оператор = (b);

    MyClass2 с(2);
    MyClass2 d = a; 
    // при такой записи при создании объекта MyClass2 d будет вызываться конструктор копирования, 
    // так как мы еще не создали объект класса MyClass2 d
    // эта запись эквивалентна записи MyClass2 d(c);

    MyClass2 e(4);
    MyClass2 f(5);
    e.operator=(f); // после создания конструктора присваивания можно писать так
    e = f; // компилятор позволяет записывать так

    MyClass2 g(6);
    MyClass2 h(7);
    MyClass2 i(8);
    g = h = i; // такая запись не сработает

    return 0; 
}

// оператор присваивания пример:
// int a = 2;
// это обычное присваивание с примитивными типами данными
// точно также можно присаивать объекты классов:
// MyClass2 a(1);
// MyClass2 b(a);
// точно также мы можем сделать с помощью оператора присваивания
// a = b;
// в этом случае у нас будет 2 пере, которые будут ссылаться на одну и ту же область памяти
// так как мы используем динамическую память 
// деструктор вызывается для каждого класса и при втором вызове мы пытаемся освободить уже освободенную память
// происходит ошибка при выполнении данной программы

// чтобы выйти из этой ситуации нам нужно написать выполнить перегрузку оператора присваивания
// конструктор оператора присваивания очень похож на конструктор копирования, но со своими отличиями
// для

