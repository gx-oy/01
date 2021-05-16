/*空指针访问成员函数*/

#include<iostream>
using namespace std;

/*C++中允许空指针调用成员函数，但要注意有没有用到 this,
如果成员函数涉及到this指针,那么this指针在成员函数里面是等于NULL的
会出错*/

class Person
{
  public:
    void showname()
    {
      cout<<"Person\n";
    }
    void showage()
    {
      if(this==NULL)//有了这个条件，代码就不会那么容易崩
      {
        cout<<"*this is NULL\n";
        return;
      }
      cout<<"age:"<<p_age<<endl;//在这里我们用到了p_age这个成员变量，其实这里默认是cout<<"age:"<<this->p_age<<endl;
      /*我们已知this是指向一个对象实体的，但是在t1()函数中，我们没有创建Person对象，只创建了一个空指针，
      此时相当于 this=NULL（而且这个语句是不允许出现在成员函数中的，因为this指针的本质是一个指针常量，不可以改变指向）
      用this去访问对象里的属性相当于用一个NULL去访问属性，当然会出错*/
    }
    int p_age;
};
void t1()
{
  Person *p=NULL;
  p->showname();//C++中允许空指针调用成员函数
  p->showage();
}

int main()
{
  t1();
  return 0;
}
