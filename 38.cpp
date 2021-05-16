/*成员函数做友元*/
#include<iostream>
#include<string>
using namespace std;

class Building;
class GoodF
{
    public:
        GoodF();
        void visit();//可以访问Building中的私有成员
        void visit2();//不可以访问Building中的私有成员
    public:
        Building *building;
};
class Building
{
    friend void GoodF::visit();//重要代码
    public:
        string b_sittingroom;
        Building();
    private:
        string b_bedroom;
};


/*********************/
Building::Building()
{
    b_sittingroom="keting";
    b_bedroom="woshi";
    cout<<"Building gouzao\n";
}
GoodF::GoodF()
{
    building=new Building;
    cout<<"GoodF gouzao\n";
}

void GoodF::visit()
{
    cout<<"public:"<<building->b_sittingroom<<endl;
    cout<<"private:"<<building->b_bedroom<<endl;
}
void GoodF::visit2()
{

}

void t1()
{
    GoodF f;
    f.visit();
}

int main()
{
    t1();
    return 0;
}
