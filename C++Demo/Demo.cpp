#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace BaseClassVirtualDestruct{
    class Base  
    {  
        public:  
            Base(){ cout<<"Constructing Base\n";}  
        // this is a destructor:  
            virtual ~Base(){ cout<<"Destroying Base\n";}  
    };  
    class Derive: public Base  
    {  
        public:  
            Derive(){ cout<<"Constructing Derive\n";}  
            ~Derive(){ cout<<"Destroying Derive\n";}  
    }; 
}

int main()  
{  
        //new delete 一个对象 基类析构函数不是析构函数 会造成内存泄漏
        BaseClassVirtualDestruct::Base *basePtr = new BaseClassVirtualDestruct::Derive();  
        delete basePtr;  
        //看支不支持c++11 
        cout <<__cplusplus<<endl;
        //##表示连接  # 表示字符串

        
  
        return 0;  
}  