#include <iostream>
#include<cstdlib>
#include<fstream>
using namespace std;
class item
{
    char name[20];
    int code,price,num;
public:
    void getdata()
    {
        cout<<"enter name,code,price,number of items\n";
        cin>>name>>code>>price>>num;
    }
    void display()
    {
        cout<<"name:"<<name<<endl;
        cout<<"code:"<<code<<endl;
        cout<<"price:"<<price<<endl;
        cout<<"number of items:"<<num<<endl;
    }
};
int main()
{
    int n;
    cout<<"enter number of ob\n";
    cin>>n;
    fstream file;
    item it;
    file.open("item",ios::out);
    file.close();
    file.open("item",ios::ate|ios::in|ios::out);
    if(file)
    {
        cout<<"success\n";
        for(int i=0;i<n;i++)
        {
            cout<<"enter detatils\n";
            it.getdata();
            file.write((char*)&it,sizeof(it));
        }
        file.seekg(0);
         for(int i=0;i<n;i++)
        {
            file.read((char*)&it,sizeof(it));
            it.display();
        }
        file.seekg(0,ios::end);

        cout<<"enter another object to add\n";
        it.getdata();
         file.write((char*)&it,sizeof(it));
         file.seekg(0);
         cout<<"after adding item\n";
        for(int i=0;i<=n;i++)
        {
            file.read((char*)&it,sizeof(it));
            it.display();
        }
        cout<<"enter object number to be modified\n";
        int n1;
        cin>>n1;
        int loc=(n1-1)*sizeof(it);
        file.seekg(0);
        file.seekp(loc);
        cout<<"enter new values\n";
        it.getdata();
        file.write((char*)&it,sizeof(it));
        cout<<"after modification\n";
        file.seekg(0);
          for(int i=0;i<=n;i++)
        {
            file.read((char*)&it,sizeof(it));
            it.display();
        }
        file.close();
    }
    else
    {
        cout<<"error in opening\n";
    }
    return 0;
}
