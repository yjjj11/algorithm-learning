#include<iostream>
#include<fstream>
#include <filesystem> // C++17及以上，用于获取当前工作目录
using namespace std;
int main() {
    fstream file;
    file.open("4.txt", ios::out );//写入
    if (!file.is_open()) {
        // 打印当前工作目录
        cout << "文件打开失败\n";

        return 0;
    }
    char str[2][256] = {
        {"好好学习"},{"天天向上"}
    };
    //file.write(str[0], sizeof(str[0]));//会把剩下的所有空格都写进去
    //file.write(str[1], strlen(str[1]));//少存换行符
    int len = strlen(str[0]);
    file.write((const char*)&len, 4);
    file.write(str[0], len);

    file.close();



    file.open("4.txt", ios::in);
    char str2[2][256] = {0};
    len = 0;
    file.read((char*)&len, 4);
    file.read(str2[0], len);
    cout << str2[0];
    return 0;
}