#include <iostream>

using namespace std;

void BubbleSort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int NotSwapped=1;
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                NotSwapped=0;
                swap(arr[j],arr[j+1]);
            }
        }
        if(NotSwapped) break;
    }
}
int main()
{
    int arr[]={60,40,50,20,30,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr,n);//no need for extra space bigO O(n^2)
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
