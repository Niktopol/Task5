#include <iostream>
#include <string>

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
        } else {
            t = b - a;
            b = t;
        }
    }
    if (a == 0) {
        std::wcout << b << std::endl;;
    } else {
        std::wcout << a << std::endl;;
    }
}

void resheto(int a) {
    a = a - 1;
    std::wstring arr = L"";
    for (int i = 0; i < a; i++) {
        arr += L'1';
    }
    for (int i = 0; i < a - 1; i++) {
        if (arr[i] == '0') {
            continue;
        } else {
            for (int j = i + 1; j < a; j++) {
                if (arr[j] != '0' and ((j + 2) % (i + 2)) == 0) {
                    arr[j] = '0';
                }
            }
        }
    }
    for (int i = 0; i < a; i++) {
        if (arr[i] == '1') {
            std::wcout << i + 2 << std::endl;
        }
    }
}

int main() {
    setlocale(0, "");
    eukldel(64, 48);
    eukldvch(64, 48);
    int a;
    std::cin >> a;
    resheto(a);
}

