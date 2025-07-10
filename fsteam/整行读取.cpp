#include<iostream>
#include<fstream>
#include <filesystem> // C++17及以上，用于获取当前工作目录
using namespace std;
int main() {
    fstream file;
    file.open("1.txt", ios::out||ios::in);
    if (!file.is_open()) {
        // 打印当前工作目录
        cout << "文件打开失败\n";
        return 0;
    }
    char str[3][1024] = { 0 };
    file.get(str[0], 1024);//无法读取换行符
    file.get();
    file.get(str[1], 1024);
    file.get();
    file.get(str[2], 1024);
    file.get();
    for (int i = 0; i < 3; i++)cout << str[i] << "\n";
    file.get(str[0], 1024, 'c');//把c当作终结符，在其之后就不读了；
    for (int i = 0; i < 3; i++) {
        file.getline(str[i], 1024);
    }
    for (int i = 0; i < 3; i++)cout << str[i] << "\n";


    return 0;
}