#include <iostream>
#include <string>
using namespace std;

/*
*   ������������� ������.
*/

class Human;
class Apple;

class Human {
public:
    void TakeApple(Apple &apple);
};

class Apple {
friend Human; // ���������, ��� ����� Apple �������� ������������� �� ��������� � ������ Apple 
public:
    Apple(int weight, string color) {
        this->weight = weight;
        this->color = color;
    }
    // friend void Human::TakeApple(Apple &apple); // �������� ������������� �������
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

// ����� ������ friend Human; ���������, ��� ����� Apple �������� ������������� �� ��������� � ������ Apple
// ��� ������, ��� � ������ Human �������� ��� private ���� � ������ �� ������ Apple

// ���������� ��������������� ������ �������� ������������ � ��� ������, ������� ������������� ������������� ������ � ����� �����.
// � ��� ����� ���� ���������.