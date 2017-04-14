#include <iostream>
#include<string>
#include<cstdlib>
using namespace std;

int main()
{
    string s1("abc");
    string s2("def");
    cout<<s1<<endl;
    cout<<s2<<endl;
    string s3(s2);
    cout<<s3;
    string s4,s5;
    cout<<"enter two strings\n";
    cin>>s4>>s5;
    string sbstr,str1;
    while(1)
    {
        int x1,x2,x3,x4,x5;
        int ch;
        char c1,c2;
        cout<<"1.compare 2.substring 3.firstoccur 4.lastoccur 5.insertatend 6.swap 7.exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:x1=s4.compare(s5);
            if(x1==0)
            {
                cout<<"equal\n";
            }
            else if(x1>0)
            {
                cout<<s4<<" is greater\n";
            }
            else if(x1<0)
            {
                cout<<s5<<" is greater\n";
            }
            break;
            case 2:cin>>sbstr;
            x2=s4.find(sbstr);
            cout<<x2;
            break;
            case 3:cout<<"enter charecter to be seached first\n";
            cin>>c1;
            x3=s4.find_first_of(c1);
            cout<<x3;
            break;
            case 4:cout<<"enter charecter to be seached last\n";
            cin>>c2;
            x4=s4.find_last_of(c2);
            cout<<x4;
            break;
            case 5:cout<<"enter substring\n";
            cin>>sbstr;
            x5=s4.length();
            s4.insert(x5,sbstr);
            cout<<s4;
            break;
            case 6:s4.swap(s5);
            cout<<"s4:"<<s4<<endl;
            cout<<"s5:"<<s5<<endl;
            break;
            case 7:exit(0);
        }

    }
    return 0;
}
