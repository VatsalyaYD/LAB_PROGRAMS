#include <iostream>
#include<string.h>
using namespace std;
class bankaccount
{
    char depositer[20];
    char acholder[20];
    char actype[20];
    int balance;
public:
    bankaccount()
    {

    }
    bankaccount(char *a,char *b,char *c,int bal)
    {
        strcpy(depositer,a);
        strcpy(acholder,b);
        strcpy(actype,c);
        balance=bal;
    }
    void deposit()
    {
        cout<<"enter amount to be deposited\n";
        int amt;
        cin>>amt;
        balance=balance+amt;
    }
    void withdraw()
    {
        cout<<"enter amount to be withdrawn\n";
        int amt;
        cin>>amt;
        if(balance<amt)
        {
            cout<<"INSUFFICIENT BALANCE!!!!!\\n";
        }
        else
            balance=balance-amt;
    }
    void display()
    {
        cout<<"name of depositor:"<<depositer<<endl;
        cout<<"name of ac holder:"<<acholder<<endl;
        cout<<"ac type:"<<actype<<endl;
        cout<<"balance:"<<balance<<endl;
    }
};
int main()
{
    cout<<"enter depositor,ac holder,ac type,balance\n";
    char a[20],d[20],c[20];
    int bal;
    cin>>a>>d>>c>>bal;
    bankaccount b(a,d,c,bal);
    b.display();
    b.deposit();
    b.display();
    b.withdraw();
    b.display();
    return 0;
}
