#include <iostream>
#include <string>
using namespace std;

/*
*   ������������� ������� ��� ������������
*/

class A {
public:
    string msgOne = "��������� ����";
private:
    string msgTwo = "��������� ���";
protected:
    string msgThree = "��������� ���";
};

class B : public A {
public:
    void PrintMsg() {
        cout << msgOne << endl; // ���� ������
        // cout << msgTwo << endl; ��� �������
        cout << msgThree << endl; // ���� ������
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    // A a;
    B b;
    b.PrintMsg();
    b.msgOne; // ���� ������
    // b.msgTwo; // ��� �������
    // b.msgThree;// ��� �������

    // cout << a.msgOne << endl;

    return 0;
}

// �������� ����� A � ����� ������ � ������� �������������� �������
// ��� ������������ ���� ������������ ������������
// ��� ������ �������� ����� B � ������������ �� ������ A ��������� public ����������� �������
// public �������� ����� ������������ ����������� ������� ��� ������������

// ��������� ���������� � �������������� ����� ������ A ������ ������ B
// � ���� � ������������� ������� public �� ����� ������
// � ���� � ������������� ������� private �� ����� �� ������
// � ���� � ������������� ������� private ����� ���������� ������ � ��� ������, ��� ��� ���� �������
// � ���� � ������������� ������� protected �� ����� �� ������
// ����������� ������� protected - ��� ���-�� ������� ����� public � private

// ��������� ���������� � �������������� ����� ������ A � ������� main
// � ���� � ������������� ������� public �� ����� ������
// � ���� � ������������� ������� private �� ����� �� ������
// � ���� � ������������� ������� protected �� ����� �� ������

// ���������� ������ ������������ ������� ��� ������������ (class B : public A)
// ���� ������� public �� private ��� protected, �� ������ � ����� ������ A ���������
// ������� 
// |                     �������� ����������� �������         |
// | ---------------------  | public    | private | protected |
// | public-������������    | public    | private | protected |
// | private-������������   | private   | private | private   |
// | protected-������������ | protected | private | protected |