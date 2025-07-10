#include<stdafx.h>
int main() {
    std::variant<std::string, int>data;
    data = "cherno";
    std::cout << std::get<std::string>(data) << "\n";
    //std::cout << std::get<int>(data) << std::endl;
    //如果在添加完字符串之后立马选择取出int类型的数据
    //就会发生系统异常
    data = 2;
    std::cout << std::get<int>(data) << std::endl;


    //如何做到无论传进来的是什么都可以辨别和使用呢？
    data = "zyt";
    if (auto value = std::get_if<std::string>(&data)) {
        std::cout << *value << "\n";
    }
    else {
        std::cout << "Its a Number\n";
    }
}