#include <iostream>
#include <string>
using namespace std;

/*
*   ќпределение методов вне класса.
*/

class MyClass {
public:
    MyClass();
    ~MyClass();
    void PrintMessage();
private:
};

MyClass::MyClass() {

}

MyClass::~MyClass() {
    
}

void MyClass::PrintMessage() {
    cout << "Hello!" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    MyClass m;
    m.PrintMessage();
    return 0;
}

// здесь мы объ€вили конструктор и деструктор внутри класса
// а саму реализацию вынесли за пределы класса