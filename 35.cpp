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
    //this 指针的本质：指针常量；指针常量的指向是不可以更改的
    void shoename() const
    {
      //this->p_age=100;//当在函数后面加了const，这一行会报错，此时这是一个常函数
    }
    int p_age;
};

void t1()
{
  
}
int main()
{
  t1();
  return 0;
}

//以上内容全部来自B站黑马程序员，这些都是我在听课的过程中做的笔记
