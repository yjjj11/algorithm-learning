#include<iostream>
#include<thread>
#include<chrono>
#include<atomic>
static std::atomic<bool>finished(false);
void Dowork(){
    
    std::cout<<"print this thread id: "<<std::this_thread::get_id()<<std::endl;

    while(!finished){
        std::cout<<"working"<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
}

int main(){

    std::thread worker(Dowork);
    std::cin.get();
    finished=true;
    worker.join();
    std::cout<<"working ending"<<std::endl;
    std::cout<<"print this thread id: "<<std::this_thread::get_id()<<std::endl;

}