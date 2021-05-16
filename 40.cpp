/*左移运算符的重载*/
#include<iostream>
using namespace std;

class Person
{
    public:
        //一般不会利用成员函数重载左移符号
        mutable int p_a;
        mutable int p_b;
};

//引用的本身是起别名，所以下面这行代码的cout 可以换成out 或者其他任何字符串，不会出错；
//但是在调用这个函数的那一行,也就是26行依旧是写cout
//返回类型为 ostream 
ostream & operator<<(ostream &cout,Person &p)//本质：operator<<(cout,p) 简化： cout<<p
{
    cout<<"p_a="<<p.p_a<<"\n";
    cout<<"p_b="<<p.p_b<<"\n";
    return cout;
}
void t1()
{
    Person p;
    p.p_a=10;
    p.p_b=20;
    cout<<p<<endl;//如何重载‘<<’运算符，是的该行代码能把 p 对象中的成员全部输出
}
int main()
{
    t1();
    return 0;
}
