#include<stdafx.h>
std::optional<std::string> readfromfile(const std::string& filepath) {
    std::ifstream stream(filepath);
    if (stream) {
        std::string result;
        //read file;

        stream.close();
        return result;
    }
    return {};
}
int main() {
    std::optional<std::string> data = readfromfile("data.txt");
    //查看文件是否存在
    std::string value = data.value_or("not present");
    std::cout << value << "\n";
    if (data) {
        std::cout << "get sucssedfully\n";
    }
    else {
        std::cout << "NO such file\n";
    }
}