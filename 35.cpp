/*const 修饰成员函数*/

#include<iostream>
using namespace std;
/*
常函数：
  1、成员函数后面加const后我们称这个函数为常函数
  2、常函数内不可以修改成员属性
  3、成员属性声明时加关键字mutable后，在常函数中可以修改
  
 常对象：
  1、声明对象前加const称该对象为常对象
  2、常对象只能调用常函数
*/

//每一个成员函数内部都隐含有一个 this 指针

class Person
{
  public:
    //this 指针的本质：指针常量；指针常量的指向是不可以更改的，指针指向的值是可以改变的。
    void showname() const //加了后面这个const，就相当于const Person* const this;也就是说后面这个const起始修饰的是this 指针
    {
      //this->p_age=100;//当在函数后面加了const，这一行会报错，此时这是一个常函数
      this->p_b=100;//此时不会报错，因为在p_b的声明前加了 mutable
    }
  void hanshu()
  {
    
  }
    int p_age;
    mutable int p_b;
};

void t1()
{
  Person p;
  p.showname();
}
void t2()
{
  const Person p=Person();//常对象；要使用隐式转换法创建对象
  //p.p_age=100;//会报错
  p.p_b=100;//不会报错
  cout<<p.p_b<<endl;
  //p.hanshu();//此时报错，因为常对象只能调用常函数，因为在非 常函数中是默认允许修改对象属性值的，而常对象却不允许，如果常对象调用非 常函数，有点自相矛盾的意思了
}
int main()
{
  t2();
  return 0;
}
