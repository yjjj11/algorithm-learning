#include<stdafx.h>
#define stringview 0
static uint32_t s_alloccount = 0;
void* operator new(size_t size) {
    s_alloccount++;
    std::cout << "Allocating cunt " << size << " bytes\n";
    return malloc(size);
}
#if stringview
void Printname(const std::string& name) {
    std::cout << name << "\n";
}
#else
void Printname(std::string_view name) {
    std::cout << name << "\n";
}
#endif
int main() {
    std::string  name = "yjj";

#if stringview
    std::string firstname = name.substr(0, 1);
    std::string secondname = name.substr(1, 2);
#else
    std::string_view firstname(name.c_str(), 2);
    std::string_view secondname(name.c_str() + 2, 1);
#endif
    Printname(name);
    Printname(firstname);
    Printname(secondname);
    std::cout << s_alloccount << "\n";
    std::cin.get();
}
//使用string_view视图可以大大加快c++性能
//一般来说普通的字符串可以用const char*来代替