#include <iostream>
#include <conio.h>
#include <limits>
using namespace std;

class dye {
public:
    int one(int n) {
        return (n - 2) * (n - 2) * 6;
    }
    int two(int n) {
        return (n - 2) * 12;
    }
    int three() {
        return 8;
    }
    int no(int n) {
        return (n - 2) * (n - 2) * (n - 2);
    }
};

class surface {
public:
    int cube(int n) {
        return n * n * 6;
    }
    int cuboid(int a, int b, int h) {
        return (a * b + a * h + b * h) * 2;
    }
};

class volume {
public:
    int cube(int n) {
        return n * n * n;
    }
    int cuboid(int a, int b, int h) {
        return a * b * h;
    }
};

void waitForXAndClearScreen() {
    while (true) {
        char key = _getch();
        if (key == 'X' || key == 'x') {
            system("cls");
            break;
        }
    }
}

void cls() {
    system("cls");
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    int n, a, b, h, num;
    int number;
    dye d;
    surface s;
    volume v;

    while (true) {
        cout << "��ӭʹ�ó������������\n1.�����\n2.���\n3.Ⱦɫ����\n4.����\n5.�˳�" << endl;
        cin >> num;
        switch (num) {
        case 1:
            cls();
            cout << "�����壬�����壿(1: ������, 2: ������)" << endl;
            while (true) {
                cin >> number;
                if (number == 1) {
                    cls();
                    cout << "�������ߣ�" << endl;
                    cin >> a >> b >> h;
                    cls();
                    cout << "������������" << s.cuboid(a, b, h) << endl;
                    waitForXAndClearScreen();
                    break;
                }
                else if (number == 2) {
                    cls();
                    cout << "�߳���" << endl;
                    cin >> n;
                    cls();
                    cout << "������������" << s.cube(n) << endl;
                    waitForXAndClearScreen();
                    break;
                }
                else {
                    cout << "��Ч���룬������1��2��" << endl;
                    clearInputBuffer();
                }
            }
            break;
        case 2:
            cls();
            cout << "�����壬�����壿(1: ������, 2: ������)" << endl;
            while (true) {
                cin >> number;
                if (number == 1) {
                    cls();
                    cout << "�������ߣ�" << endl;
                    cin >> a >> b >> h;
                    cls();
                    cout << "�����������" << v.cuboid(a, b, h) << endl;
                    waitForXAndClearScreen();
                    break;
                }
                else if (number == 2) {
                    cls();
                    cout << "�߳���" << endl;
                    cin >> n;
                    cls();
                    cout << "�����������" << v.cube(n) << endl;
                    waitForXAndClearScreen();
                    break;
                }
                else {
                    cout << "��Ч���룬������1��2��" << endl;
                    clearInputBuffer();
                }
            }
            break;
        case 3:
            cls();
            cout << "�߳���" << endl;
            cin >> n;
            cls();
            cout << "����Ϳɫ������" << d.three() << endl
                << "����Ϳɫ������" << d.two(n) << endl
                << "һ��Ϳɫ������" << d.one(n) << endl
                << "û����Ϳɫ������" << d.no(n) << endl;
            waitForXAndClearScreen();
            break;
        case 4:
            cls();
            break;
        case 5:
            cout << "�ټ�" << endl;
            system("pause");
            return 0;
        default:
            cout << "�����ѡ����������룺" << endl;
            clearInputBuffer();
        }
    }
    system("pause");
}