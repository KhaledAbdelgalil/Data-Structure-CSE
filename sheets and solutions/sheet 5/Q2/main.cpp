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
    int arr2[]={100,65,8,40,34,7,2,9,13};
    int arr3[]={100,65,45,30,28,23,7,5,1};
    cout<<"Q2-a"<<endl;
    isHeap(arr1,9)?cout<<"is heap":cout<<"not a heap";
    cout<<endl;
    cout<<"Q2-b"<<endl;
    isHeap(arr2,9)?cout<<"is heap":cout<<"not a heap";
    cout<<endl;
    cout<<"Q2-c"<<endl;
    isHeap(arr3,9)?cout<<"is heap":cout<<"not a heap";
    return 0;
}
