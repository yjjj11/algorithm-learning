 #include<iostream>
#include<fstream>
#include <filesystem> // C++17及以上，用于获取当前工作目录
using namespace std;
int main() {
    fstream file;
    file.open("2.txt", ios::out || ios::binary);//写入
    if (!file.is_open()) {
        // 打印当前工作目录
        cout << "文件打开失败\n";
        return 0;
    }
    char str[2][256] = {
        {"好好学习"},{"天天向上"}
    };
    file.write(str[0], sizeof(str[0]));//会把剩下的所有空格都写进去
    file.write(str[1], strlen(str[1]));//少存换行符
    int len = strlen(str[0]);
    file.write((const char*)&len, 4);
    file.write(str[0], len);

    file.close();
    return 0;
}