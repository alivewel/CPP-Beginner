#include <iostream>
#include <string>
using namespace std;

class Human {
public:
    string name;
};

class Student : public Human {
public:
    string group;
};

class Professor : public Human {
public:
    string subject;
};

int main() {


    return 0;
}

// класс от которого происходит наследование называется базовым или родительским
// класс которой унаследовался от базового класса производный, дочерний, потомок или наследник

// унаследуем класс Human в классах Student и Professor через модификатор : public Human
