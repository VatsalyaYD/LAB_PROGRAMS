#include <iostream>
#include<cstdlib>
using namespace std;
const int size=5;
class que
{
    int f,r;
    int a[size];
public:
    que()
    {
        f=-1;
        r=-1;
    }
    ~que()
    {

    }
    que enq()
    {
        try
            {
                if(r==size-1)
                    throw(1);
                else
                {
                   if(f==-1&&r==-1)
                {
                        f=r=0;
                }
                    else
                    {
                        r++;
                    }
                    cout<<"enter ele";
                    int ele;
                    cin>>ele;
                    a[r]=ele;
            }
        }
        catch(int i)
        {
            cout<<"queue full\n";
        }
return *this;
    }
    que deq()
    {
        try
        {
            if((f==-1&&r==-1)||f>r)
                throw 1;
            else
            {
               cout<<"deleted elemt is="<<a[f];
               if(r==f)
               {
                   r=f=-1;
               }
               else
                f++;
            }
        }
        catch(int i)
        {
            cout<<"stack empty";
        }
return *this;

    }
    void display()
    {
        try
        {
            if((f==-1&&r==-1)||f>r)
                throw 1;
            else
            {
                int i;
        for(i=f;i<=r;i++)
        {
            cout<<a[i]<<"\t";
        }
        }
        }
        catch(int i)
        {
            cout<<"queue empty";
        }

    }
};
int main()
{
    que q;
    int ch;
    while(1)
    {
        cout<<"1.enq 2.deq 3.display 4.exit\n";
        cout<<"enter choice\t";
        cin>>ch;
        switch(ch)
        {
            case 1:
                  q.enq();
        break;
        case 2:q.deq();
        break;
        case 3:q.display();
        break;
        case 4:exit(0);
        break;

    }
   }
    return 0;
}
