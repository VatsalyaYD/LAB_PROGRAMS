// A Generic selectSort sort.
#include <iostream>
using namespace std;
template <class X>
void selectSort( X *A, int n)
{
	int i,j;
	X iMinPos,iTemp;
	for(i=0;i<n;i++)
	{
		iMinPos = i;
		for(j=i+1;j<n;j++)
		{
			if(A[j]<A[iMinPos])
				iMinPos = j;
		}
		iTemp = A[i];
		A[i] = A[iMinPos];
		A[iMinPos] = iTemp;
	}
}

template <class X>
void insertSort( X *A, int n)
{
	int i, j;
	X iKey;
	for(i=1;i<n;i++)
	{
		iKey = A[i];
		j = i-1;
		while(j>=0 && A[j] > iKey)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = iKey;
	}
}

int main()
{
    int iarray[7] = {7, 5, 4, 3, 9, 8, 6};
    double darray[5] = {4.3, 2.5, -0.9, 100.2, 3.0};
    int i;
    cout << "Here is unsorted integer array: ";
    for(i=0; i<7; i++)
        cout << iarray[i] << ' ';
    cout << endl;
    cout << "Here is unsorted double array: ";
    for(i=0; i<5; i++)
        cout << darray[i] << ' ';
    cout << endl;
    selectSort(iarray, 7);
    insertSort(darray, 5);
    cout << "Here is sorted integer array: ";
    for(i=0; i<7; i++)
    cout << iarray[i] << ' ';
    cout << endl;
    cout << "Here is sorted double array: ";
    for(i=0; i<5; i++)
    cout << darray[i] << ' ';
    cout << endl;
    return 0;
}

