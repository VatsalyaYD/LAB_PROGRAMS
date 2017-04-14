/*
11. Write a C++ program to create a class called STUDENT with data members USN, Name and Age. 
Using Inheritance create the classes UGSTUDENT and PGSTUDENT having fields as Semester, Fees and Stipend. 
Enter the data for at least 5 students. 
Find the Semesterwise average age for all UG and PG students separately.
*/

#include <iostream>
using namespace std;

class STUDENT              //Base class
{
protected:
	char Name[20];
	int Regno,Age;
public:
	void ReadStudentDetails();
};

void STUDENT::ReadStudentDetails()
{
    cout << "Name : ";
    cin >> Name;
    cout << "RegNo : ";
    cin >> Regno;
    cout << "Age : ";
    cin >> Age;
}
class Ugstudent:public STUDENT              //Derived class
{
	    int Semester,Fees,Stipend;
    public:
	    void ReadData();
	    friend void semWiseAvgUGAge(Ugstudent*, int n);
};

class Pgstudent:public STUDENT    //Derived Class
{
	    int Semester,Fees,Stipend;
    public:
	    void ReadData();
	    friend void semWiseAvgPGAge(Pgstudent*, int n);
};

void Ugstudent::ReadData()
{
    ReadStudentDetails();       //call Base class function
    cout << "Semester  :";
    cin >> Semester;
    cout << "Fees   :";
    cin >> Fees;
    cout << "Stipend   :";
    cin >> Stipend;
}


void Pgstudent::ReadData()
{
    ReadStudentDetails();       //call Base class function
    cout << "Semester  :";
    cin >> Semester;
    cout << "Fees   :";
    cin >> Fees;
    cout << "Stipend   :";
    cin >> Stipend;
}

void semWiseAvgUGAge(Ugstudent *list, int n)
{
    int sem, i, found, sum, count;

    for(sem = 1; sem<=8; sem++)
    {
        found = sum = count = 0;
        for(i=0;i<n;i++)
        {
            if(list[i].Semester == sem)
            {
                sum = sum + list[i].Age;
                found = 1;
                count++;
            }
        }

        if(found == 1)
            cout << "\nAvergage Age for Semester " << sem << " : " << (float)sum/count;
    }
}

void semWiseAvgPGAge(Pgstudent *list, int n)
{
    int sem, i, found, sum, count;

    for(sem = 1; sem<=8; sem++)
    {
        found = sum = count = 0;
        for(i=0;i<n;i++)
        {
            if(list[i].Semester == sem)
            {
                sum = sum + list[i].Age;
                found = 1;
                count++;
            }
        }

        if(found == 1)
            cout << "\nAvergage Age for Semester " << sem << " : " << (float)sum/count;
    }
}

int main()
{
    Ugstudent UG[20];
    Pgstudent PG[20];
    
    int i,n;
    cout << "How many students (enter more than 4) ?";
    cin >> n;
    cout << "\n\n***Enter the details of UG students��********\n\n";
    
    for(i=0;i<n;i++)
    {
        cout << "\nEnter the details of student :" << i << endl;
        UG[i].ReadData();
    }

    cout << "\n*******Enter the details of PG students�..*****\n";

    for(i=0;i<n;i++)
    {
        cout << "\n Enter the details of student:" << i << endl;
        PG[i].ReadData();
    }

    semWiseAvgUGAge(UG,n);
    semWiseAvgPGAge(PG,n);

    return 0;
}
