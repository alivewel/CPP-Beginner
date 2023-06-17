#include <iostream>
#include <string>
using namespace std;

/*
*   Дружественные классы.
*/

class Human;
class Apple;

class Human {
public:
    void TakeApple(Apple &apple);
};

class Apple {
friend Human; // указываем, что класс Apple является дружественным по отношению к классу Apple 
public:
    Apple(int weight, string color) {
        this->weight = weight;
        this->color = color;
    }
    // friend void Human::TakeApple(Apple &apple); // указание дружественной функции
private:
    int weight;
    string color;
};

void Human::TakeApple(Apple &apple) {
    cout << "TakeApple " << apple.weight <<  " " << apple.color << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    Apple a(100, "red");
    Human h;
    h.TakeApple(a);
    return 0;
}

// через запись friend Human; указываем, что класс Apple является дружественным по отношению к классу Apple
// это значит, что в классе Human доступны все private поля и методы из класса Apple

// функционал дружественности класса нарушает инкапсуляцию в том классе, который предоставляет дружественный доступ к своим полям.
// с ней нужно быть острожней.