#include <iostream>

/*
*    Rvalue-ссылки 
*/

class MyClass {
public:
    int* data;

    MyClass(int value) {
        data = new int(value);
        std::cout << "Constructor: " << *data << std::endl;
    }

    // Move конструктор
    MyClass(MyClass&& other) noexcept {
        data = other.data;
        other.data = nullptr;
        std::cout << "Move Constructor: " << *data << std::endl;
    }

    ~MyClass() {
        delete data;
        std::cout << "Destructor" << std::endl;
    }
};

int main() {
    MyClass obj1(42); // Создание объекта obj1

    MyClass obj2(std::move(obj1)); // Использование move конструктора

    // Проверка, что obj1.data равно nullptr после перемещения
    std::cout << "obj1.data: " << obj1.data << std::endl;

    // Проверка, что obj2.data содержит правильное значение
    std::cout << "obj2.data: " << *obj2.data << std::endl;

    return 0;
}
