#include <iostream>
#include <string>
using namespace std;

/*
*   ������������� ������� � ������
*/

class Test; // ����� class Point ���� � ������������� class Test

class Point {
private:
    int x;
    int y;
    // friend void ChangeX(Point &value); ����� ���� ����� �������
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
    // this. �� ��������
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

// ������������� ������� �� ��������� � ������ ���������� �� �������, ������� 
// �� �������� ������ ������ ��� ����� ������ � �������� ����� ������
// ��� ����, ����� ������� ����� ������������ � ����� ������ ����� ��������� friend void ChangeX(Point &value);

// �������� ������� ChangeX, � ������� ����� ���������� � �������� ����� ������ Point
// ���������� ��������� ��� �������� ����� this
// ��� ��� ������� ChangeX �� �������� ������ ������, � �������� ����� this
// ��������� �� ������� �����
// ��� ��� ������� ChangeX ������������� , �� �� �������� ������ ������
// ������ � ������� ����� �������� ����� this �� �� ����� �������� ������ � ������� �����
// �� ����� �������� ������ � ����� ������ ����� ������ (��������: value.x)

// �� ����������� ������������� ������� � ������ �� ���������������� ������������ �������
// ��� ������ ��� ����������� friend void ChangeX(Point &value);
// �� ����� ������� � ����� ����, � private ��� public

// ����� ���� ������� ����� ���� ������������ �� ��������� � ���������� �������
// �������� ������� Test, �������� � ��� ��������� ���� Data � ������, ��� ������� ChangeX ��� ���� �������������
// ������ ��������� � ���� Data �� ������� ChangeX 
// ������ ������� ChangeX ����� ���������� � �������� ������ Point � Test
