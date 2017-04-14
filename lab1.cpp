#include <iostream>
#include<math.h>
using namespace std;
class circle
{
    int r,x,y;
public:
    circle()
    {
        r=x=y=0;
    }
    circle(int a,int b,int c)
    {
        r=a;
        x=b;
        y=c;
    }
    void display()
    {
        cout<<"radius="<<r<<endl;
        cout<<"x="<<x<<endl;
        cout<<"y="<<y<<endl;
    }
   friend void check(circle,circle);
};
void check(circle c1,circle c2)
{
    int l,d;
    l=c1.r+c2.r;cout<<"sum="<<l;
    d= sqrt(((c2.x - c1.x)*(c2.x - c1.x) + (c2.y - c1.y)*(c2.y - c1.y)));

    cout<<"distance="<<d;
    if(d>l)
    {
        cout<<"circles dont intersect\n";
    }
    else if(l==d)
    {
        cout<<"circles touch each other\n";
    }
    else
    {
        cout<<"circles intersect\n";
    }
}
int main()
{
    circle c1(5,10,0);
    circle c2(5,0,0);
    circle c3(5,12,0);
    check(c1,c2);      //touch
    check(c1,c3);      //intersect
    check(c2,c3);
    return 0;
}
