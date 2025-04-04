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
        cout << "欢迎使用长方体和正方体\n1.表面积\n2.体积\n3.染色问题\n4.清屏\n5.退出" << endl;
        cin >> num;
        switch (num) {
        case 1:
            cls();
            cout << "长方体，正方体？(1: 长方体, 2: 正方体)" << endl;
            while (true) {
                cin >> number;
                if (number == 1) {
                    cls();
                    cout << "长、宽、高？" << endl;
                    cin >> a >> b >> h;
                    cls();
                    cout << "长方体表面积：" << s.cuboid(a, b, h) << endl;
                    waitForXAndClearScreen();
                    break;
                }
                else if (number == 2) {
                    cls();
                    cout << "边长？" << endl;
                    cin >> n;
                    cls();
                    cout << "正方体表面积：" << s.cube(n) << endl;
                    waitForXAndClearScreen();
                    break;
                }
                else {
                    cout << "无效输入，请输入1或2：" << endl;
                    clearInputBuffer();
                }
            }
            break;
        case 2:
            cls();
            cout << "长方体，正方体？(1: 长方体, 2: 正方体)" << endl;
            while (true) {
                cin >> number;
                if (number == 1) {
                    cls();
                    cout << "长、宽、高？" << endl;
                    cin >> a >> b >> h;
                    cls();
                    cout << "长方体体积：" << v.cuboid(a, b, h) << endl;
                    waitForXAndClearScreen();
                    break;
                }
                else if (number == 2) {
                    cls();
                    cout << "边长？" << endl;
                    cin >> n;
                    cls();
                    cout << "正方体体积：" << v.cube(n) << endl;
                    waitForXAndClearScreen();
                    break;
                }
                else {
                    cout << "无效输入，请输入1或2：" << endl;
                    clearInputBuffer();
                }
            }
            break;
        case 3:
            cls();
            cout << "边长？" << endl;
            cin >> n;
            cls();
            cout << "三面涂色个数：" << d.three() << endl
                << "两面涂色个数：" << d.two(n) << endl
                << "一面涂色个数：" << d.one(n) << endl
                << "没有面涂色个数：" << d.no(n) << endl;
            waitForXAndClearScreen();
            break;
        case 4:
            cls();
            break;
        case 5:
            cout << "再见" << endl;
            system("pause");
            return 0;
        default:
            cout << "错误的选项，请重新输入：" << endl;
            clearInputBuffer();
        }
    }
    system("pause");
}