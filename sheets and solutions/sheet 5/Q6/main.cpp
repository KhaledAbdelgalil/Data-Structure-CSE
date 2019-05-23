#include <bits/stdc++.h>
using namespace std;

void counting_edges(int arr[],int n)
{
    int count=0;
    for(int i=0;i<=(n-2)/2;i++)
    {
        if(arr[i*2+1]>arr[i]) count++;
        if(2*i+2<n&&arr[2*i+2]>arr[i]) count++;
    }
    cout<<count;
}
int main()
{
    int arr[]={19,14,28,15,16,7,27,15,21,21,5,2};
    counting_edges(arr,12);
    return 0;
}
