#include <bits/stdc++.h>
using namespace std;

bool isHeap(int arr[],int n)
{
    for(int i=0;i<=(n-2)/2;i++)
    {
        if(arr[i*2+1]>arr[i]) return false;
        if(2*i+2<n&&arr[2*i+2]>arr[i]) return false;
    }
    return true;
}
int main()
{
    int arr1[]={10,15,8,20,14,17,12,9,13};

    cout<<"Q3"<<endl;
    isHeap(arr1,9)?cout<<"is max heap":cout<<"not a max heap";

    return 0;
}
