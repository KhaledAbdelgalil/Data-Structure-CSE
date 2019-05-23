#include <iostream>
using namespace std;//Best-Case:O(n) worst and averageCase O(n^2)

void InsertionSort(int arr[],int n)
{
    int j,key;
    for(int i=1;i<n;i++)//first element is sorted
    {
         key=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
int main()
{
    int arr[]={80,90,60,30,50,70,40};
    int n=sizeof(arr)/sizeof(arr[0]);
    InsertionSort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
