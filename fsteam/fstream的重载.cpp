#include<iostream>
#include<fstream>
#include <filesystem> // C++17及以上，用于获取当前工作目录
using namespace std;
int main() {
    fstream file;
    file.open("5.txt", ios::out );//写入
    if (!file.is_open()) {
        // 打印当前工作目录
        cout << "文件打开失败\n";

        return 0;
    }
    int x = 666;
    char str[] = "输入输出，明天头图";
    file << x << "\n";//重载运算符<<，全部转成字符串录入
    file << str << "\n";
    file.close();
    return 0;
}