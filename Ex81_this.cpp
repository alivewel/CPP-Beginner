#include <iostream>
#include <string>
using namespace std;

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
    void Print() {
        std::cout << "X = " << x << "\nY = " <<  y << std::endl;
    }
    void setX(int valueX) {
        x = valueX;
    }
    // void setY(int y) {
    //     y = y; // при такой записи значения y не меняется
    // }
    void setY(int y) { 
        this->y = y; // вот такая запись более корректная
    }
};

int main() 
{ 
    Point a;
    a.setY(3);
    a.Print();

    return 0; 
}

// ключевое слово this - это адрес объекта самого объекта
// 