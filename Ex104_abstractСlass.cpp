#include <iostream>
#include <string>
using namespace std;

/*
*    ����������� �����. ����� ����������� �������. virtual. override.
*/

class Weapon {
public:
    virtual void Shoot() = 0; // ����� ������ ���������� ����������� �����
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
    void Shoot(Weapon *weapon) { // ������ �� ���� ��������� ��������� �� ����������� ����� Weapon
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

// ����������� ������� - ��� ���� �� �������� ���������� ������������.
// � ��� ����� ��������� ������� � ���������� ������� � ���� �������.
// �� ����� ���� ��� ������� ����� �� �������.
// �� ���� ������� ���� ������� ����� ���� ���� ���������� � ����������� �� ����������.

// � ��� ���� ����� �������� � �������� ���� ����� ����������, ������� �������� ��������� ����������
// ��� ����� ��� ����������� ����� ��������-�������, ������� ����� �������� ����������� ����������
// ����� ������� �� ����� �� ������ �������� ������������ ����� ��������-������� � �������������� � ��� �����

// ����� ������� Shoot � ������ Gun ����� ���� �������������� � ������ ��������-�������, 
// � ������ Gun ������� Shoot ����� ������� �����������
// �� ��� ����� ����� ������� ������ ������ Gun � ������� � ���� ������� Shoot

// �������� ����� SubmachineGun ������������ �� ������ Gun � ������������� ������� Shoot
// ����� ������ ��� ����� ��������
// �� ��� ����, ��� ����� �������������� ��������� ������ Shoot, ����� ������ �� ����������
// � ��� ������ ���� ����� ����� �� ��������� ������� void Shoot() 
// ��� ���� ����� ���������� �� ��� ������������� ��� �� ����� ������� �������� ����� override
// �� ���� �������� ����� override ��������� �������� �� ������������ ��������� ��������� �������

// �������� ����� Player � � ��� �������� ����� Shoot, ������� ����� ��������� ��������� �� ������ ���� Gun
// �������� ������ � ����� ���������� ��� ����� �� ������� �� ����� ��������

// ���� �� �� ���� ����������� �������, �� ��� � ������ Player ��������� ��� ������� ������ ����������� � ����������� ���
// ����������� ������� ��������� �������� �����
