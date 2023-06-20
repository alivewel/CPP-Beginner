#include <iostream>
 
// класс сообщения
class Message
{
public:
    Message(std::string data) : text{new std::string(data)} { // выделяем память 
        id = ++counter;
        std::cout << "Create message " << id << std::endl;
    }
    Message(const Message& copy) : Message{copy.getText()} {
        std::cout << "Copy  message " << copy.id << " to " << id << std::endl;
    }
    // конструктор перемещения
    Message(Message&& moved) : text{moved.text} {
        id = ++counter;
        std::cout << "Move message " << moved.id << " to " << id << std::endl;
        moved.text = nullptr;
    }
    // перемещение данных происходит в строке text{moved.text}
    // В данном случае text{moved.text} инициализирует член-переменную text текущего объекта
    // с помощью перемещения данных из moved.text. Это означает, что указатель на данные text 
    // в объекте moved перемещается в указатель text текущего объекта. После этого moved.text 
    // становится nullptr, так как перемещение "забирает" данные у исходного объекта и "оставляет" его 
    // в состоянии, которое не владеет данными.
    ~Message() { 
        std::cout << "Delete message "  << id << std::endl;
        delete text;    // освобождаем память
    }

    std::string& getText() const { return *text; }
    unsigned getId() const {return id;}
private:
    std::string* text;  // текст сообщения
    unsigned id{};  // номер сообщения
    static inline unsigned counter{};   // статический счетчик для генерации номера объекта
};
// класс мессенджера, который отправляет сообщение
class Messenger
{
public:
    Messenger(Message mes): message{std::move(mes)} { }
    void sendMessage() const {
        std::cout << "Send message " <<  message.getId() << ": " << message.getText() << std::endl;
    }
private:
    Message message;
};
 
int main() {
    // Messenger telegram{Message{"Hello Word"}};
    // telegram.sendMessage();

    Message obj1("Hello"); // Создание объекта с помощью конструктора
    Message obj2(std::move(obj1)); // Вызов конструктора перемещения

    // std::cout << "message obj1 "  << obj1.getText() << std::endl;
    std::cout << "message obj2 "  << obj2.getText() << std::endl;
    std::cout << "message obj1 "  << obj1.getText() << std::endl;
    
    // if (obj1.text == nullptr) {
    // if (obj1.getText() != nullptr) {
    // std::cout << "obj1 no longer exists or is in an invalid state" << std::endl;
    // } else {
    //     std::cout << "obj1 still exists" << std::endl;
    // }



}

// Здесь параметр moved представляет перемещаемый объект. 
// Мы не вызваем стандартный конструктор, как в случае с конструктором копирования, 
// потому что нам не надо выделять память. Вместо этого мы просто передаем в переменную text
// значение указателя (адрес блока выделенной памяти) из перемещаемого объекта moved text{moved.text}. 
// Таким образом мы избегаем ненужного дополнительного выделения памяти. И чтобы указатель text 
// перемещаемого объекта moved перестал указывать на эту область памяти, и соответственно чтобы в деструкторе 
// объекта moved не было ее освобождения, передаем указателю значение nullptr.