#include <iostream>
// using namespace std;

class Point {
private: 
    int x;
    int y;
public:
    Point() { // конструктор по умолчанию, мы сами описали как он работает
        x = 0;
        y = 0;
    }
    Point(int valueX, int valueY) {
        x = valueX;
        y = valueY;
    }
    Point(double valueX, double valueY) {
        x = valueX;
        y = valueY;
    }
    void Print() {
        std::cout << "X = " << x << "\nY = " <<  y << std::endl;
    }
    void setX(int valueX) {
        x = valueX;
    }
    void setY(int valueY) {
        y = valueY;
    }
};

int main() 
{ 
    Point a;
    a.Print();
    Point b(2, 3);
    b.Print();
    Point c(5.1, 6.2);
    c.Print();
    return 0; 
}

// Перегрузка конструктора - это копия конструктора по умолчанию в Классе, который на вход принимает другой тип и количество аргументов.
// Таких конструкторов может быть несколько штук.
// 