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
    char str[10240] = { 0 };
    int n = 0;
    while (!file.eof()) {
        str[n++] = file.get();
    }
    cout << str;
    file.close();
    return 0;
}