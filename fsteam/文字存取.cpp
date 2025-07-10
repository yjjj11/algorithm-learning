#include<iostream>
#include<fstream>
#include <filesystem> // C++17及以上，用于获取当前工作目录
using namespace std;
int main() {
    fstream file;
    file.open("2.txt", ios::out);//写入
    char str[] = "asugfduiqw";
    if (!file.is_open()) {
        // 打印当前工作目录
        cout << "文件打开失败\n";
        return 0;
    }
    file.write(str, sizeof(str));
    file.close();

    file.open("2.txt", ios::in);
    char str2[100] = { 0 };

    file.read(str, 100);
    cout << str << "\n";
    file.close();
    return 0;
}