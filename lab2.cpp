#include <iostream>

using namespace std;
class duration
{
    int hh,mm,ss;
public:
    duration()
    {
        hh=0;
        mm=0;
        ss=0;
    }
    duration(int a,int b,int c)
    {
        hh=a;
        mm=b;
        ss=c;
    }
    void getduration()
    {
        cout<<"enter time hh:mm:ss\n";
        cin>>hh>>mm>>ss;
        if(ss>60)
        {
            ss=ss-60;
            mm+=1;
        }
        if(mm>60)
        {
            mm=mm-60;
            hh+=1;
        }
        if(hh>24)
        {
          hh=0;
        }

    }
    void display()
    {
        cout<<"time is\n";
        cout<<hh<<":"<<mm<<":"<<ss;
    }
    void addtime(duration,duration);
};
void duration:: addtime(duration t1,duration t2)
{
    duration t3;int h,m,s;
    s=t1.ss+t2.ss;
    m=t1.mm+t2.mm+s/60;
    h=t1.hh+t2.hh+m/60;
   ss=s%60;
   mm=m%60;
   hh=h;
}
int main()
{
    duration t1,t2,t3;
    t1.getduration();
    t1.display();
    t2.getduration();
    t2.display();
    t3.addtime(t1,t2);
    cout<<"add\n";
    t3.display();
    return 0;
}
