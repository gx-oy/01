/*加号运算符重载*/
//运算符重载概念：对已有的运算符重新进行定义，赋予其另外的功能，以适应不同的数据类型

#include<iostream>
using namespace std;

//加号运算符重载作用：实现两个自定义数据类型相加的运算
class Person
{
    public:
        int p_a;
        int p_b;
        //1、成员函数实现运算符重载
        //Person operator*
       /* Person operator+(Person &p)//加减乘除都可以吗？ 可以，只要把operator+改成operator/*- 就可以实现四则运算了
        {
            Person t;
            t.p_a=p.p_a+this->p_a;
            t.p_b=p.p_b+this->p_b;
            return t;
        }*/
};

//2、全局函数实现运算符重载
Person operator+(Person &p1,Person &p2)
{
    Person t;
    t.p_a=p1.p_a+p2.p_a;
    t.p_b=p1.p_b+p2.p_b;
    return t;
}
//运算符重载也可以发生函数重载，如：
Person operator+(Person &p,int num)
{
    Person t;
    t.p_a=p.p_a+num;
    t.p_b=p.p_b+num;
    return t;
}
void t1()
{
    Person p1;
    p1.p_a=10;
    p1.p_b=20;
    Person p2;
    p2.p_a=1;
    p2.p_b=2;
    //本质是Person P3=p1.operator+(p2);或者p3=operator+(p1,p2);
    Person p3=p1+p2;
    cout<<p3.p_a<<endl;
    cout<<p3.p_b<<endl;
    
    //函数重载
    p3=p1+10;//本质为 ： p3=operator+(p1,10);
    cout<<p3.p_a<<endl<<p3.p_b<<endl;
}
int main()
{
    t1();
    return 0;
}
