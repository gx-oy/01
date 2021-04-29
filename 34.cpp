/*空指针访问成员函数*/

#include<iostream>
using namespace std;

//C++中允许空指针调用成员函数，但要注意有没有用到 this

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
        return;
      }
      cout<<"age:"<<p_age<<endl;//在这里我们用到了p_age这个成员变量，其实这里默认是cout<<"age:"<<this->p_age<<endl;
      //我们已知this是指向一个对象实体的，但是在t1()函数中，我们没有创建Person对象，只创建了一个空指针，此时相当于 this=NULL（当然了，这个语句是不允许出现在成员函数中的，具体原因35.cpp有讲）；还用this去访问对象里的属性，当然会出错
    }
    int p_age;
};
void t1()
{
  Person *p=NULL;
  p->showname();//C++中允许空指针调用成员函数
  p->showage();//这一行不能执行，但是22行能运行。原因见showage()函数；
}

int main()
{
  t1();
  return 0;
}
//以上内容，全部来自B站黑马程序员，这相当于我是在听课的过程中做的笔记
