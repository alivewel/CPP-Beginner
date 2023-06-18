#include <iostream>
#include <string>
using namespace std;

/*
*    интерфейсы
*/

class IBicycle {
public:
    void virtual TwistTheWheel() = 0; // крутить колесо
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

// в чистом языке Си++ интерфейсов нет в отличии от Java C#
// но в них нет множественного наследования и в Си++ есть
// поэтому в Си++ наличие какого-то специального ключевого слова не требуется
// Интерфейс - это договоренность как можно с чем-то взаимодействовать
// создавать экземпляр самого интерфейса нам не нужно
// потому если мы не знаем от чего этот интерфейс, то мы не знаем как это работает

// у нас есть класс человек, в котором есть метод Ездить на чем-то
// этот метод принимает на вход указатель на интерфейс IBicycle
// в интерфейсе IBicycle есть виртуальные методы TwistTheWheel и Ride