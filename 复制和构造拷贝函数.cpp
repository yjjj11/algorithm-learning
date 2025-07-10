#include<bits/stdc++.h>
using namespace std;
#include<memory>
class String{
private:
    char * buffer;
    int size;
public:
    String(const char* string){
        cout<<"create node now\n";
        size=strlen(string);
        buffer=new char[size+1];//因为还需要存储休止符
        memcpy(buffer,string,size+1);
    }
    ~String(){
        cout<<"destroyed node now \n";
        delete[] buffer;//因为buffer是一个char[]指针
    }
    String(const String& other)//在后面加上==delete，该类将无法复制
    {   
        size=other.size;
        buffer=new char[size+1];
        memcpy(buffer,other.buffer,size+1);
        //在复制别人的内容时，专门为自己再开一个新的buffer地址
        //再将原来buffer中的内容复制过来即可
    }
    
    
    char& operator[](const int index){
        return buffer[index];
    } //要返回想要修改的那个位置的地址

    //加上友元就可以访问其私有类
    friend ostream& operator<<(ostream& stream,const String & string);
};
ostream& operator<<(ostream& stream,const String & string){
    cout<<string.buffer;
    return stream;
}
int main(){
    String fi="cherno";
    String second=fi;
    //如果不重写复制构造函数，那么second中的buffer和fi中的相同
    //main结束之后，两者将会同时delete同一个地址，导致系统崩溃
    //需要重写复制构造函数为second分配属于自己的buffer

    second[2]='a';
    cout<<fi<<"\n";
    cout<<second<<"\n";//必须重载一下<<

}