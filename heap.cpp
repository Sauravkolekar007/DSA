// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void heapify(int ar[], int n, int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n&&ar[left]>ar[largest])
    largest=left;

    if(right<n&&ar[right]>ar[largest])
    largest=right;

    if(largest!=i)
    {
        swap(ar[i], ar[largest]);
        heapify(ar,n, largest);
    }
}

void heapsort(int ar[], int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(ar,n,i);
    }

    for(int i=n-1;i>0;i--)
    {
        swap(ar[0], ar[i]);
        heapify(ar,i,0);
    }
}

void printAr(int ar[], int n)
{
    for(int i=0;i<n;++i)

    cout<<ar[i]<<"\n";
    cout<<"\n";

}

int main()
{
    int ar[]={89,73,287,92,7,27,91,23,38};
    int n=sizeof(ar)/sizeof(ar[0]);

    heapsort(ar, n);

    cout<<"Sorted array is : \n";
    printAr(ar, n);
    return 0;

}
