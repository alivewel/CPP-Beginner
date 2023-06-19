#include <iostream>
#include <string>
using namespace std;

/*
*    интерфейсы
*/

class IBicycle {
public:
    void virtual TwistTheWheel() = 0; // крутить руль
    void virtual Ride() = 0; // ездить
};

class SimpleBicycle : public IBicycle {
public:
    void TwistTheWheel() override {
        cout << "Метод TwistTheWhell класс SimpleBicycle" << endl;
    }
    void Ride() override {
        cout << "Метод Ride класс SimpleBicycle" << endl;
    }
};

class SportBicycle : public IBicycle {
public:
    void TwistTheWheel() override {
        cout << "Метод TwistTheWhell класс SportBicycle" << endl;
    }
    void Ride() override {
        cout << "Метод Ride класс SportBicycle" << endl;
    }
};

class Human {
public:
    void RideOn(IBicycle &bicycle) {
        cout << "Крутим руль" << endl;
        bicycle.TwistTheWheel();
        cout << "Поехали" << endl;
        bicycle.Ride();
    }
};


int main() {
    SimpleBicycle sb;
    SportBicycle sportB;

    Human h;
    h.RideOn(sb);
    h.RideOn(sportB);

    return 0;
}

// в чистом языке Си++ интерфейсов нет в отличии от Java и C#
// но в них нет множественного наследования и в Си++ есть
// поэтому в Си++ наличие какого-то специального ключевого слова не требуется
// Интерфейс - это договоренность как можно с чем-то взаимодействовать
// создавать экземпляр самого интерфейса нам не нужно
// потому если мы не знаем от чего этот интерфейс, то мы не знаем как это работает

// Абстрактный класс - это тот класс, в котором есть хоть один виртуальный метод
// Интерфейс - это по сути абстрактный класс, в котором все методы чисто виртуальные
// Все методы в интерфейсе IBicycle должны быть виртуальными


// у нас есть класс человек, в котором есть метод Ездить на чем-то
// этот метод принимает на вход указатель на интерфейс IBicycle
// в интерфейсе IBicycle есть виртуальные методы TwistTheWheel и Ride

// создадим класс Human, в нем реализуем метод 
// который будет принимать ссылку на объект который реализует интерфейс IBicycle
// создадим класс SimpleBicycle и унаследуемся от интерфейса IBicycle
// вообще говорить унаследуемся от интерфейса неправильно, правильно будет сказать реализуем интерфейс
// и создадим класс SportBicycle, по сути копия SimpleBicycle

// в Си++ у нас множественное наследование неограничено,
// один объект у нас может реализовывать несколько интерфейсов 
