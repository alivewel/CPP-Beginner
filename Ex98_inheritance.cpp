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
        cout << "� �����!" << endl;
    }
};

class ExtramuralStudent : public Human {
public:
    string group;
    void Learn() {
        cout << "� �������!" << endl;
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
    st.SetName("����");
    cout << st.GetName() << endl;

    ExtramuralStudent extraSt;
    extraSt.Learn();
    extraSt.SetName("����");
    cout << extraSt.GetName() << endl;

    Professor pr;

    return 0;
}

// ����� �� �������� ���������� ������������ ���������� ������� ��� ������������
// ����� ������� ������������� �� �������� ������ �����������, ��������, ������� ��� ���������

// ���������� ����� Human � ������� Student � Professor ����� ����������� : public Human
// �� ����� ��� ���� name �������������� �� ������ Human

// �������� ����� ����� ExtramuralStudent � ������������ �� ������ Human
// ��������� ������ Learn() � ������� Student � ExtramuralStudent.
// ��� ������ ���� ������� �� �����, ��� � ������� ������ ��� ������ ����.

// ������� ��������� ���� name � ������ Human
// ������� ������ � ������ ��� ����� ����
// ��� �������� st � extraSt ������� ������ ������ � ������ 
// ��� ���� name �� ������ Human