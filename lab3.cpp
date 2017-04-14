#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
class rainguage
{
    float cm;
    char city[20];
public:
    rainguage()
    {

    }
    void read()
    {
        cout<<"enter city name\n";
        cin>>city;

    srand(time(NULL));

    cm= ((rand()%20+1000)/1000.0);
    }
    void display()
    {
        cout<<"city:"<<city<<endl;
        cout<<"rainfall:"<<cm<<endl;
    }
    friend void avg(rainguage a[],int);
};
void avg(rainguage a[3],int n)
{
    float average=0.0;
    int i;
    for(i=0;i<n;i++)
    {
        average+=a[i].cm;
    }
    average=average/n;
    cout<<"average rainfall received="<<average;
}
int main()
{
   rainguage a[10];
   cout<<"enter number of cities\n";
   int n;
   cin>>n;
   int i;
   for(i=0;i<n;i++)
   {
       a[i].read();
   }
   for(i=0;i<n;i++)
   {
       a[i].display();
   }
   avg(a,n);
    return 0;
}
