#include <iostream>
#include <string>
using namespace std;

/*
*    Перегрузка оператора сложения
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

     bool operator ==(const Point &other) {
        return this->x == other.x && this->y == other.y;
    }
    bool operator !=(const Point &other) {
        return !(this->x == other.x && this->y == other.y);
    }

    Point operator +(const Point &other) {
        Point temp; // создадим временный объект класса Point
        temp.x = this->x + other.x; // сложим значений полей текущего и другого класса
        temp.y = this->y + other.y; // сложим значений полей текущего и другого класса
        return temp;
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
    Point b(9, 4);

    // Point c = a + b; // корректная запись
    Point c = a.operator+(b); // корректная запись
    c.Print();

    // std::cout << "result = " << result << std::endl;
    

    return 0; 
}

// оператор сложения по умолчанию не перегружен
// тип возвращаемого значения это объект класса Point, не указатель на Point, а просто Point
