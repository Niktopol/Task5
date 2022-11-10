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
bool find(char a) {
    a = tolower(a);
    std::wstring s = L"aeiouy";
    for (wchar_t sym : s) {
        if (sym == a) {
            return true;
        }
    }
    return false;
}
int slgcnt(std::string s) {
    int i = 0;
    for (char a: s) {
        i += find(a);
    }
}
std::string prep(std::string si){
    char i;
    std::string so = "";
    for (char a: si){
        a = tolower(a);
        if (a == ' '){
            if (i < 0){
                continue;
            }else{
                if (i == ' '){
                    continue;
                }else{
                    so += a;
                    i = a;
                }
            }
        }else{
            if (int(a) >= 97 and int(a) <= 122){
                so += a;
                i = a;
            }
        }
    }
    return so;
}
std::string split(std::string si){
    std::string so = "";
    char prev = 0;
    int slg = slgcnt(si);
    bool glas = false;
    if (slg > 1){
        for (int i = 0; i < si.length(); i++) {
            if (int(prev) == 0){
                so += si[i];
                prev = si[i];
                if (find(si[i])){
                    glas = true;
                }
            }else if (slg <= 1){
                so += si[i];
                prev = si[i];
            }else{
                if (glas){
                    if (find(si[i])){
                        if (si[i] == prev){
                            so += si[i];
                            prev = si[i];
                        } else{
                            so += si[i]+'-';
                            prev = 0;
                        }
                        slg -= 1;
                    }
                }else{
                    so += si[i];
                    prev = si[i];
                }
            }
        }
    }
    std::cout << so << std::endl;
    return so;
}
void slogs() {
    std::ifstream in;
    std::ofstream out;
    in.open("words.txt");
    out.open("wordsaout.txt");
    std::string all;
    std::string allout;
    std::string t;
    if (!in.is_open() or !out.is_open()) {
        std::cout << "Один из файлов не существует" << std::endl;
    } else{
        while (getline(in, t)) {
            all += t + ' ';
        }
        all = prep(all);
        t = "";
        for (char a: all){
            if (a == ' '){
                if (!t.empty()){
                    allout += split(t) + " ";
                    t = "";
                }
            }else{
                t += a;
            }
        }
        out << allout;
    }
}

int main() {
    setlocale(0, "");
    int a = 0,b = 0;
    int* ab[] = {&a, &b};
    while (true){
        std::cout << "Введите номер задания" << std::endl;
        safe_inp(&a,-1);
        switch (a) {
            case 1:
                if(safe_inp(ab, 2, -1)){
                    eukldel(abs(a), abs(b));
                    eukldvch(abs(a), abs(b));
                } else{
                    std::cout << "Неверный ввод" << std::endl;
                }
                break;
            case 2:
                std::cout << "Введите число, входящее в интервал (2,100000)" << std::endl;
                if (safe_inp(&a,-1) and a > 2 and a < 100000){
                    resheto(a);
                } else{
                    std::cout << "Неверный ввод" << std::endl;
                }
                break;
            case 3:
                break;
            case 4:
                slogs();
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

