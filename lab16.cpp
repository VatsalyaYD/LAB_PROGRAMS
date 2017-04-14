#include <iostream>
#include<cstdlib>
using namespace std;
const int size=5;
template<class t>
class sample
{
    t *p;
    int top;
public:
    sample()
    {
        top=-1;
        p=new t[size];
    }
    bool isempty()
    {
        if(top==-1)
            return 1;
        else
            return 0;
    }
    bool isfull()
    {
        if(top==size-1)
            return 1;
        else
            return 0;
    }
    sample push(t);
    sample pop();
    void display()
    {
        int i;
        for(i=top;i>=0;i--)
        {
            cout<<p[i];
        }
    }
};
template<class t>
sample<t> sample<t>::push(t ele)
{
    top++;
    p[top]=ele;
    return *this;
}
template<class t>
sample<t>sample<t>::pop()
{
    cout<<"deleted ele="<<p[top];
    top--;
    return *this;
}
int main()
{
    int ch,ele;
    sample<int>s1;
    while(1)
    {
        cout<<"1.push 2.pop 3.display 4.exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                if(s1.isfull())
            {
                cout<<"stack full\n";
            }
            else
            {
                cout<<"enter element to be pushed\n";
            cin>>ele;
            s1.push(ele);
        }
        break;
        case 2:if(s1.isempty())
            {
                cout<<"stack empty\n";
            }
            else
            s1.pop();
            break;
        case 3:if(s1.isempty())
            {
                cout<<"stack empty\n";
            }
            else
            s1.display();
            break;
            case 4:exit(0);

    }

}
    return 0;
}
