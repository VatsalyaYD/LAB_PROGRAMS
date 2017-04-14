#include <iostream>

using namespace std;
const int size=5;
class mat
{
    int m,n;
    int a[size][size];
public:
    void getorder()
    {
        cout<<"enter matrix order\n";
        cin>>m>>n;
    }
    
    void getdata()
    {

        int i,j;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }
    }

    friend ostream& operator<<(ostream &,mat&);
    bool operator==(mat);
    mat operator*(mat);
};

ostream& operator<<(ostream& dout,mat &x)
{
     int i,j;
         for(i=0;i<x.m;i++)
        {
            for(j=0;j<x.n;j++)
            {
                dout<<x.a[i][j];
            }
            dout<<"\n";
        }
        return dout;
}

mat mat::operator*(mat x)
{
    mat m3;
    m3.m=m;
    m3.n=x.n;

    int i,j,k;

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            m3.a[i][j]=0;
            for(k=0;k<n;k++)
            {
            m3.a[i][j]=a[i][k]*x.a[k][j]+m3.a[i][j];
        }
    }
    }
    return m3;
}

bool mat::operator==(mat x)
{
   if(n==x.m)
    return 1;
   else
    return 0;
}


int main()
{
    mat m1,m2,m3,m4;

    m1.getorder();
    m2.getorder();
    
    if(m1==m2)
    {
        cout<<"enter elements of matrix 1\n";
        m1.getdata();
       cout<<m1;
         cout<<"enter elements of matrix 2\n";
       m2.getdata();
        cout<<m2;
        cout<<"product:\n";
        m3=m1*m2;
        cout<<m3;
    }
    else
    {
        cout<<"not compatible\n";
    }

    return 0;
}
