#include <iostream>
#include <string>
using namespace std;

/*
*   Дружественные функции и классы
*/

class Test; // чтобы class Point знал о существовании class Test

class Point {
private:
    int x;
    int y;
    // friend void ChangeX(Point &value); здесь тоже можно указать
public:
    Point() {
        x = 0;
        y = 0;
        std::cout << this << " constructor" << std::endl;
    }
    Point(int valueX, int valueY) {
        x = valueX;
        y = valueY;
        std::cout << this << " constructor" << std::endl;
    }
    void Print() {
        std::cout << "X = " << x << "\nY = " <<  y << std::endl;
    }
    // void setX(int valueX) {
    //     x = valueX;
    // }
    // void setY(int y) { 
    //     this->y = y;
    // }
    friend void ChangeX(Point &value, Test &testValue);
};

class Test {
private:
    int Data = 0;
    friend void ChangeX(Point &value, Test &testValue);
};

void ChangeX(Point &value, Test &testValue) {
    value.x = -1;
    testValue.Data = -1;
    // this. не работает
}

int main() {
    setlocale(LC_ALL, "RU");
    Point a(5, 12);
    a.Print();
    Test t;
    ChangeX(a, t);
    a.Print();

    return 0;
}

// дружественная функция по отношению к классу называется та функция, которая 
// не является членом класса она имеет доступ к закрытым полям класса
// для того, чтобы функция стала дружестенной в конце класса нужно прописать friend void ChangeX(Point &value);

// создадим функцию ChangeX, в которой будем обращаться к закрытым полям класса Point
// интересное замечание про ключевое слово this
// так как функция ChangeX не является членом класса, а ключевое слово this
// указатель на текущий класс
// так как функция ChangeX дружественная , но не является членом класса
// доступ к объекту через ключевое слово this мы не можем получить доступ к никаким полям
// мы можем получать доступ к полям только через объект (Например: value.x)

// на определение дружественной функции в классе не распространяются модификаторы доступа
// это значит что определение friend void ChangeX(Point &value);
// мы можем указать в любой зоне, в private или public

// также одна функция может быть дружестенной по отношению к нескольким классам
// создадим функцию Test, создадим в нем приватное поле Data и укажим, что функция ChangeX для него дружественная
// теперь обратимся к полю Data из функции ChangeX 
// теперь функция ChangeX может обращаться к объектам класса Point и Test
