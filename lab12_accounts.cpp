/*
12. Create class called ACCOUNT that stores customer name, account number and type of the account. 
    From this derive the classes CUR_ACCT and SAV_ACCT. 
    Include necessary member functions in order to achieve the following tasks 
        i. Accept deposit from a customer and update the balance. 
        ii. Compute the deposit interest. 
        iii. Permit withdrawal and update the balance. 
        iv. Check for the minimum balance, impose penalty and update the balance.
*/

#include <iostream>

using namespace std;

//Account (BASE CLASS)
class account
{
   protected: 
    char name[20];
    char type[20];
    int acnum;
   public:
    void virtual getdata()=0;
    void virtual deposit()=0;
    void virtual withdraw()=0;
    void virtual display()=0;
    void virtual check()=0;
    void virtual interest()=0;
};

//Savings Account
class sa:public account
{
    float balance;
public:
    void getdata()
    {
        cout<<"enter name,type,acnum,bal\n";
        cin>>name>>type>>acnum>>balance;
    }
    void display()
    {
        cout<<"name:"<<name<<endl;
        cout<<"type:"<<type<<endl;
        cout<<"acnum:"<<acnum<<endl;
        cout<<"bal:"<<balance<<endl;
    }
    void deposit()
    {
        cout<<"enter amt to be deposited\n";
        int amt;
        cin>>amt;
        balance+=amt;
    }
     void withdraw()
    {
        cout<<"enter amt to be withdraw\n";
        int amt;
        cin>>amt;
        balance-=amt;
    }
    void check()
    {
        if(balance<500)
            balance-=100;
    }
    void interest()
    {
        int r=5;
        int inte=(balance*r)/100.0;
        balance+=inte;
    }

};

//Current Account
class ca:public account
{
    float balance;
public:
    void getdata()
    {
        cout<<"enter name,type,acnum,bal\n";
        cin>>name>>type>>acnum>>balance;
    }
    void display()
    {
        cout<<"name:"<<name<<endl;
        cout<<"type:"<<type<<endl;
        cout<<"acnum:"<<acnum<<endl;
        cout<<"bal:"<<balance<<endl;
    }
    void deposit()
    {
        cout<<"enter amt to be deposited\n";
        int amt;
        cin>>amt;
        balance+=amt;
    }
     void withdraw()
    {
        cout<<"enter amt to be withdraw\n";
        int amt;
        cin>>amt;
        balance-=amt;
    }
    void check()
    {
        if(balance<1000)
            balance-=100;
    }
    void interest()
    {
        int r=10;
        balance+=(balance*r)/100.0;
    }

};

// Main Function
int main()
{
    int i=0;
    account *ptr[100];
    char ch;
    int op;

    do
    {
        cout<<"enter s.savings c.current\n";
        cin>>ch;

        if(ch=='s')
            ptr[i]=new sa;
        else
            ptr[i]=new ca;

        cout<<"enter info\n";
        ptr[i]->getdata();
        i++;
        cout<<"1.continue 2.stop";
        cin>>op;

    }while(op==1);

    int ob,c;

    while(1)
    {
        cout<<"enter object number\n";
        cin>>ob;
        cout<<"1.deposit 2.interest 3.withdraw 4.display\n";
        cin>>c;

        switch(c)
        {
            case 1:ptr[ob-1]->deposit();
            break;
            case 2:ptr[ob-1]->interest();
            break;
            case 3:ptr[ob-1]->withdraw();
            break;
            case 4:ptr[ob-1]->display();
            break;
        }
    }

    return 0;
}
