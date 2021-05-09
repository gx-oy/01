/*第一种友元的实现：全局函数做友元*/
#include<iostream>
#include<string>
using namespace std;

/*友元的目的就是让一个函数或者类访问另一个类中私有成员  关键字为friend*/

class Building
{
    //意味着GoodF()函数被允许访问 Building 中的私有成员
    friend void GoodF(Building *building);//本次课核心代码！！

  public:
    string b_sittingroom;
  Building()
  {
    this->b_sittingroom="客厅";
    this->b_bedroom="卧室";
    cout<<"gouzao"<<endl;
  }
  private:
    string b_bedroom;
};

//全局函数
void GoodF(Building *building)
{
    cout<<"your good friend is in your "<<building->b_sittingroom<<endl;//访问公共属性
    cout<<"your good friend is in your "<<building->b_bedroom<<endl;//访问私有属性
}

void t1()
{
    Building B;
    GoodF(&B);
}

int main()
{
  t1();
  return 0;
}
