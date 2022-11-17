#include <iostream>
#include <string>
#include <limits>
#include <fstream>

bool safe_inp(double* arr[], int len, double err) {
    double n;
    bool rs = true;
    for (int i = 0; i < len; i++) {
        if (!(std::wcin >> n)) {
            std::wcin.clear();
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            *arr[i] = err;
            rs = false;
        }
        else {
            *arr[i] = n;
        }
    }
    return rs;
}
bool safe_inp(double* x, double err) {
    double n;
    if (!(std::wcin >> n)) {
        std::wcin.clear();
        std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        *x = err;
        return false;
    }
    else {
        *x = n;
        return true;
    }
}
bool safe_inp(int* arr[], int len, int err) {
    int n;
    bool rs = true;
    for (int i = 0; i < len; i++) {
        if (!(std::wcin >> n)) {
            std::wcin.clear();
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            *arr[i] = err;
            rs = false;
        }
        else {
            *arr[i] = n;
        }
    }
    return rs;
}
bool safe_inp(int* x, int err = -1) {
    int n;
    if (!(std::wcin >> n)) {
        std::wcin.clear();
        std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        *x = err;
        return false;
    }
    else {
        *x = n;
        return true;
    }
}
void eukldel(int a, int b) {
    int t = 0;
    if (a < b) {
        t = a;
        a = b;
        b = t;
    }
    while (b != 0) {
        t = a - (b * (int(a / b)));
        a = b;
        b = t;
    }
    std::wcout << a << std::endl;
}
void eukldvch(int a, int b) {
    int t = 0;
    while (b != 0 and a != 0) {
        if (a > b) {
            t = a - b;
            a = t;
        }
        else {
            t = b - a;
            b = t;
        }
    }
    if (a == 0) {
        std::wcout << b << std::endl;;
    }
    else {
        std::wcout << a << std::endl;;
    }
}
void resheto(int a) {
    std::wstring arr = L"";
    for (int i = 0; i < a; i++) {
        arr += L'1';
    }
    for (int i = 2; i < a - 1; i++) {
        if (arr[i] == '0') {
            continue;
        }
        else {
            for (int j = i + i; j < a; j+=i) {
                arr[j] = '0';
            }
        }
    }
    for (int i = 2; i < a; i++) {
        if (arr[i] == '1') {
            std::wcout << i << std::endl;
        }
    }
}
void acii() {
    std::ifstream in;
    std::ofstream out;
    in.open("toas.txt");
    out.open("outas.txt");
    std::string t;
    if (!in.is_open() or !out.is_open()) {
        std::cout << "Один из файлов не существует" << std::endl;
    }
    else {
        while (getline(in, t)) {
            for (char a : t) {
                out << int(a) << "\n";
            }
        }
    }
    in.close();
    out.close();
}
char findnr(char a, int mv) {
    a = tolower(a);
    std::string eng = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < eng.length(); i++) {
        if (eng[i] == a) {
            return eng[(i + mv) % (eng.length())];
        }
    }
    return a;
}
std::string move(std::string s, int mv) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == tolower(s[i])) {
            s[i] = findnr(s[i], mv);
        }
        else {
            s[i] = toupper(findnr(tolower(s[i]), mv));
        }
    }
    return s;
}
void cyph(int i) {
    std::ifstream in;
    std::ofstream out;
    in.open("tocy.txt");
    out.open("outcy.txt");
    std::string t;
    if (!in.is_open() or !out.is_open()) {
        std::cout << "Один из файлов не существует" << std::endl;
    }
    else {
        while (getline(in, t)) {
            out << move(t, i) << "\n";
        }
    }
    in.close();
    out.close();
}
int main() {
    setlocale(0, "");
    int a = 0, b = 0;
    int* ab[] = { &a, &b };
    while (true) {
        std::cout << "Введите номер задания" << std::endl;
        safe_inp(&a, -1);
        switch (a) {
            case 1:
                if (safe_inp(ab, 2, -1)) {
                    eukldel(abs(a), abs(b));
                    eukldvch(abs(a), abs(b));
                }
                else {
                    std::cout << "Неверный ввод" << std::endl;
                }
                break;
            case 2:
                std::cout << "Введите число, входящее в интервал (2,100000)" << std::endl;
                if (safe_inp(&a, -1) and a > 2 and a < 100000) {
                    resheto(a);
                }
                else {
                    std::cout << "Неверный ввод" << std::endl;
                }
                break;
            case 3:
                acii();
                break;
            case 4:
                if (safe_inp(&a, -1)) {
                    cyph(a);
                }
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                std::cout << "Неверный ввод" << std::endl;
        }
    }
}