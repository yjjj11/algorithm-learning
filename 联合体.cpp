#include<bits/stdc++.h>
struct vector2{
    float x,y;
};
struct vector4{
    // float x,y,z,w;
    // vector2& getA(){
    //     return *(vector2*)&x;
    // }

    union{
        struct{
            float x,y,z,w;
        };
        struct{
            vector2 a,b;
        };
    };

};
int main(){
    struct Union{
        union{float a;int b;};

    };
    Union u;
    u.a=2.0f;
    std::cout<<u.a<<" "<<u.b<<"\n";
    //联合体智能存储一单元，u.b相当于该内容的内存地址int化
    
}