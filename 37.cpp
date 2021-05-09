/*类做友元*/
#include<iostream>
#include<string>
using namespace std;

class Building
{
    friend class GoodF;//关键代码段
    public:
        Building();
        string b_sittingroom;
    private:
        string b_bedroom;
};

Building::Building()//构造函数
{
    cout<<"gouzao 1 \n";
    b_sittingroom="客厅";
    b_bedroom="卧室";
}

class GoodF
{
    public:
        GoodF();
        Building *building;
        void visit();//访问building中的属性
};

GoodF::GoodF()//构造函数
{
    cout<<"gouzao 2 \n";
    building=new Building;
}
void GoodF::visit()
{
    cout<<"your friend is in your "<<building->b_sittingroom<<endl;
    cout<<"your friend is in your "<<building->b_bedroom<<endl;//好朋友可以访问私有成员
}

void t1()
{
    GoodF p;
    p.visit();
}

int main()
{
    t1();
    return 0;
}
