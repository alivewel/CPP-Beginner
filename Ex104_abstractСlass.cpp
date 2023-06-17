#include <iostream>
#include <string>
using namespace std;

/*
*    Абстрактный класс. Чисто виртуальные функции. virtual. override.
*/

class Weapon {
public:
    virtual void Shoot() = 0; // такая запись обозначает абстрактный класс
};

class Gun : public Weapon {
public:
    void Shoot() override {
        cout << "Bang!" << endl;
    }
};

class SubmachineGun : public Gun {
public:
    void Shoot() override {
        cout << "Bang! Bang! Bang!" << endl;
    }
};

class Bazooka : public Weapon {
public:
    void Shoot() override {
        cout << "BADABOOM!" << endl;
    }
};

class Knife : public Weapon {
public:
    void Shoot() override {
        cout << "VJUH!" << endl;
    }
};

class Player {
public:
    void Shoot(Weapon *weapon) { // теперь на вход принимаем указатель на абстрактный класс Weapon
        weapon->Shoot();
    }
};



int main() {
    setlocale(LC_ALL, "Russian");
    Gun gun;
    SubmachineGun machineGun;
    Bazooka bazooka;
    Knife knife;

    Player player;
    player.Shoot(&gun);
    player.Shoot(&machineGun);
    player.Shoot(&bazooka);
    player.Shoot(&knife);

    // Gun *weapon = &machineGun;
    // weapon->Shoot();

    return 0;
}

// виртуальные функции - это один из способов реализации полиморфизма.
// у нас будет несколько классов и одинаковые функции в этих методах.
// но вести себя эти функции будут по разному.
// по сути объекты этих классов будут сами себя определять в зависимости от реализации.

// у нас есть класс Пистолет у которого есть метод выстрелить, который стреляет одночными выстрелами
// нам нужно еще реализовать класс Пистолет-пулемет, который будет стрелять несколькими выстрелами
// таким образом мы можем от класса пистолет унаследовать класс Пистолет-пулемет и переопределить в нем метод

// чтобы функцию Shoot в классе Gun можно было переопределить в классе Пистолет-пулемет, 
// в классе Gun функцию Shoot нужно сделать виртуальной
// Мы все также можем вызвать объект класса Gun и вызвать у него функцию Shoot

// создадим класс SubmachineGun унаследуемся от класса Gun и переопределим функцию Shoot
// такая запись уже будет работать
// но для того, что точно контролировать сигнатуру метода Shoot, чтобы ничего не перепутать
// у нас должна быть точно такая же сигнатура функции void Shoot() 
// для того чтобы компилятор за нас контролировал это мы можем указать ключевое слово override
// То есть ключевое слово override добавляет проверку на правильность написания сигнатуры функции

// создадим класс Player и в нем создадим метод Shoot, который будет принимать указатель на объект типа Gun
// создадим игрока и будем передавать ему пушку из которой он будет стрелять

// если бы не было виртуальных функций, то нам в классе Player создавать для каждого оружия конструктор и перегружать его
// виртуальные функции позволяют избежать этого
