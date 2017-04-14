#include <iostream>

using namespace std;
class fraction
{
    int num,den;
public:
    friend ostream& operator<<(ostream&,fraction&);
    friend istream& operator>>(istream&,fraction&);
    bool operator==(fraction);
    fraction operator+(fraction);
    fraction simplify();
};
ostream& operator<<(ostream& dout,fraction& f)
{
    dout<<"fraction is:"<<f.num<<"/"<<f.den<<endl;
    return dout;
}
istream& operator>>(istream& din,fraction &f)
{
        cout<<"enter numerator and denominator\n";
        din>>f.num>>f.den;
        return din;
}
bool fraction::operator==(fraction f)
{
    if(num==f.num&&den==f.den)
    {
        return 1;
    }
    else
        return 0;
}
fraction fraction::operator+(fraction f)
{
    fraction f3;
    if(den==f.den)
    {
    f3.num=num+f.num;
    f3.den=den;
    f3.simplify();
    }
    int m,n,r;
    m=den;n=f.den;
    while(n!=0)
    {
        r=m%n;
        m=n;
        n=r;
    }
    int lcm=(den*f.den)/m;
    cout<<"lcm="<<lcm;
    int x,y;
    num=num*(lcm/den);
    f.num=f.num*(lcm/f.den);
    f3.num=num+f.num;
    f3.den=lcm;
    return f3;
}
fraction fraction::simplify()
{
     int i;
     for(i=num;i>=1;i--)
     {
         if((num%i==0)&&(den%i==0))
         {
             num=num/i;
             den=den/i;
         }
     }
      for(i=den;i>=1;i--)
     {
         if((num%i==0)&&(den%i==0))
         {
             num=num/i;
             den=den/i;
         }
     }

}
int main()
{
    fraction f1,f2,f3;
    cout<<"enter fraction 1\n";
    cin>>f1;
    f1.simplify();cout<<f1;
    cout<<"enter fraction 2\n";
    cin>>f2;
    f2.simplify();
    cout<<f2;
    if(f1==f2)
    {
        cout<<"equal\n";
    }
    else
        cout<<"not equal\n";
    f3=f1+f2;
    cout<<"sum";
    cout<<f3;
    cout<<"after simplification\n";
    f3.simplify();
    cout<<f3;
    return 0;
}
