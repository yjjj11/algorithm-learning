#include<iostream>
#include<chrono>
#include<thread>
using namespace std::literals::chrono_literals;
class timer{
public:
    std::chrono::_V2::system_clock::time_point start,end;
    //std::chrono::time_point<std::chrono::steady_clock> start,end
    std::chrono::duration<float> durations;
    timer(){
        start=std::chrono::high_resolution_clock::now();
    }
    ~timer(){
        end=std::chrono::high_resolution_clock::now();
        durations=end-start;
        float ms=durations.count()*1000.0f;
        std::cout<<"整个程序的执行时间是： "<<ms<<std::endl;
    }
};
void function(){
    timer ti;
    for(int i=0;i<1000;i++){
        std::cout<<"hello"<<std::endl;
    }
}
int main(){

    //第一种方法
    // auto start=std::chrono::high_resolution_clock::now();
    // std::this_thread::sleep_for(1s);//动作
    // auto end=std::chrono::high_resolution_clock::now();

    // std::chrono::duration<float> durations=end-start;
    // std::cout<<durations.count()<<"s"<<std::endl;

    function();
    std::cin.get();
}