#include <iostream>
#include <string>
using namespace std;

/*
*   Спецификаторы доступа при наследовании
*/

class A {
public:
    string msgOne = "Сообщение один";
private:
    string msgTwo = "Сообщение два";
protected:
    string msgThree = "Сообщение три";
};

class B : public A {
public:
    void PrintMsg() {
        cout << msgOne << endl; // есть доступ
        // cout << msgTwo << endl; нет доступа
        cout << msgThree << endl; // есть доступ
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    // A a;
    B b;
    b.PrintMsg();
    b.msgOne; // есть доступ
    // b.msgTwo; // нет доступа
    // b.msgThree;// нет доступа

    // cout << a.msgOne << endl;

    return 0;
}

// создадим класс A с тремя полями с разными модификаторами доступа
// при наследовании тоже используются модификаторы
// для начала создадим класс B и унаследуемся от класса A используя public модификатор доступа
// public наиболее часто используемый модификатор доступа при наследовании

// попробуем обратиться к унаследованным полям класса A внутри класса B
// к полю с модификатором доступа public мы имеем доступ
// к полю с модификатором доступа private мы имеем не доступ
// к полю с модификатором доступа private можно обращаться только в том классе, где они были созданы
// к полю с модификатором доступа protected мы имеем не доступ
// модификатор доступа protected - это что-то среднее между public и private

// попробуем обратиться к унаследованным полям класса A в функции main
// к полю с модификатором доступа public мы имеем доступ
// к полю с модификатором доступа private мы имеем не доступ
// к полю с модификатором доступа protected мы имеем не доступ

// рассмотрим другие модификаторы доступа при наследовании (class B : public A)
// если сменить public на private или protected, то доступ к полям класса A изменится
// Таблица 
// |                     Исходный модификатор доступа         |
// | ---------------------  | public    | private | protected |
// | public-наследование    | public    | private | protected |
// | private-наследование   | private   | private | private   |
// | protected-наследование | protected | private | protected |