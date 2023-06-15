#include <iostream>
#include <string>
using namespace std;

class Human {
private:
    string name;
public:
    string GetName() {
        return name;
    }
    void SetName(string name) {
        this->name = name;
    }
};

class Student : public Human {
public:
    string group;
    void Learn() {
        cout << "я учусь!" << endl;
    }
};

class ExtramuralStudent : public Human {
public:
    string group;
    void Learn() {
        cout << "я заочник!" << endl;
    }
};

class Professor : public Human {
public:
    string subject;
};

int main() {
    setlocale(LC_ALL, "Russian");

    Student st;
    st.Learn();
    st.SetName("јлик");
    cout << st.GetName() << endl;

    ExtramuralStudent extraSt;
    extraSt.Learn();
    extraSt.SetName("√оша");
    cout << extraSt.GetName() << endl;

    Professor pr;

    return 0;
}

// класс от которого происходит наследование называетс€ базовым или родительским
// класс которой унаследовалс€ от базового класса производный, дочерний, потомок или наследник

// унаследуем класс Human в классах Student и Professor через модификатор : public Human
// мы видим что поле name унаследовалось от класса Human

// создадим новый класс ExtramuralStudent и унаследуемс€ от класса Human
// реализуем методы Learn() в классах Student и ExtramuralStudent.
// при вызове этих методов мы видим, что у каждого класса эти методы свои.

// сделаем приватным поле name в классе Human
// напишим геттер и сеттер дл€ этого пол€
// ƒл€ объектов st и extraSt вызовем методы геттер и сеттер 
// дл€ пол€ name из класса Human