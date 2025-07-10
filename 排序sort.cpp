#include<iostream>
#include<vector>
#include<algorithm>

int main(){
    std::vector<int> value={3,5,1,6,8};
    std::sort(value.begin(),value.end());
    std::sort(value.begin(),value.end(),std::greater<int>());
    std::sort(value.begin(),value.end(),[](int a,int b){return a<b;});
    std::sort(value.begin(),value.end(),[](int a,int b){
        if(a==1)return false;
        if(b==1)return true;//return true意味着a排在前面
        return a<b;
    });
    for(int j:value){
        std::cout<<j<<"\n";
    }
    std::cin.get();

}