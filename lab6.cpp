#include <iostream>

using namespace std;
class dm;
class db
{
    float feet,inches;
public:
    void read()
    {
        cout<<"enter feet and inches\n";
        cin>>feet>>inches;
    }
    void display()
    {
        cout<<feet<<"feets"<<inches<<"inches";
    }
    friend void add(dm &,db&);
};
class dm
{
    float m,cm;
    public:
    void read()
    {
        cout<<"enter m and cm\n";
        cin>>m>>cm;
    }
    void display()
    {
        cout<<m<<"m"<<cm<<"cm";
    }
    friend void add(dm &,db&);
};
void add(dm &ob1,db &ob2)
{
    int i,f;
    ob2.feet=(ob1.m)*3.280+ob2.feet;
    ob2.inches=(ob2.feet*12)+(ob1.cm)*0.393+ob2.inches;
    f=ob2.inches/12;
    i=int(ob2.inches)%12;
    ob2.feet=f;
    ob2.inches=i;
}
int main()
{
    dm ob1;
    db ob2;
    ob1.read();
    ob2.read();
    add(ob1,ob2);
    ob2.display();
    return 0;
}
