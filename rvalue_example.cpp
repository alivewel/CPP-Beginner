#include <iostream>

/*
*    Rvalue-ссылки 
*/

void processValue(int&& value) {
    // Обработка значения
    std::cout << "Processed value: " << value << std::endl;
}

int main() {
    processValue(42); // Передача временного объекта
    return 0;
}

// Левосторонние (lvalue) и правосторонние (rvalue) значения

// R-value ссылки (или просто r-value) в C++ — это ссылки, которые могут быть
// привязаны только к временным (r-value) выражениям. Введение r-value ссылок
// является одной из основных нововведений в стандарте C++11.
// R-value ссылки обозначаются двумя амперсандами (&&) после типа данных, например:
// int&& x = 5;

// R-value ссылки могут быть связаны только с временными (r-value) объектами, которые
// являются временными выражениями или объектами, которые находятся в состоянии,
// когда их можно безопасно перемещать (например, объекты, которые больше не
// нужны или были явно перемещены с помощью функции std::move()).

// R-value ссылки обычно используются для реализации семантики перемещения (move
// semantics) в C++. Они позволяют передавать временные объекты эффективно и без
// лишних копирований. Реализация семантики перемещения позволяет переносить
// ресурсы из одного объекта в другой, вместо их копирования, что может быть очень
// полезным для объектов с большими данными или ресурсами, например, для работы
// с большими массивами или файлами.