#include <iostream>
#include <string>
using namespace std;

/*
*    Перегрузка оператора равенства и неравенства
*/

class Point {
private: 
    int x;
    int y;
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

    // bool operator == (const Point &other) {
    //     if (this->x == other.x && this->y == other.y) {
    //         return true;
    //     } else {
    //         return false;
    //     }
    // }
    // можно написать гораздо проще
    bool operator ==(const Point &other) {
        return this->x == other.x && this->y == other.y;
    }
    bool operator !=(const Point &other) {
        return !(this->x == other.x && this->y == other.y);
    }
    void Print() {
        std::cout << "X = " << x << "\nY = " <<  y << std::endl;
    }
    void setX(int valueX) {
        x = valueX;
    }
    void setY(int y) { 
        this->y = y; 
    }
};

int main() {
    Point a(5, 1);
    // Point b(5, 1);
    Point b(9, 4);

    bool result = a != b; // компилятор ругается при такой записи, потому что в классе Point не реализован оператор равенства
                          // реализации по умолчания нету
    std::cout << "result = " << result << std::endl;
    

    return 0; 
}

// оператор равенства должен сравнивать между собой поля объектов класса
// если поля равны, значит и объекты равны
// результатом функции сравнения должен быть объекты равны или не равны
// для этого хорошо подходит тип возвращаемого значения bool

// для оператора неравенства просто инвертируем результат сравнения
