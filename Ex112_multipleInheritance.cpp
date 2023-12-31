#include <iostream>
#include <string>
using namespace std;

/*
*    множественное наследование 
*/

class Car {
public:
    void Use() {
        cout << "Я еду!" << endl;
    }
};

class Airplane {
public:
    void Use() {
        cout << "Я лечу!" << endl;
    }
};

class FlyingCar : public Car, public Airplane {

};

int main() {
    FlyingCar fc;
    ((Car)fc).Use(); // приведение типов
    ((Airplane)fc).Use(); // приведение типов
    return 0;
}

// у нас есть 2 класса с одинаковым методом Use(), но с разной реализацией этого метода
// у нас есть третий класс который наследуется от обоих этих классов (множественное наследование)
// при создании объекта третьего класса и при попытке вызвать унаследованную функцию
// компилятор начинает ругаться, он не знает какой именно метод использовать
// чтобы явно указать какую функцию использовать нужно сделать приведение типов к необходимому классу (Car)fc или (Airplane)fc