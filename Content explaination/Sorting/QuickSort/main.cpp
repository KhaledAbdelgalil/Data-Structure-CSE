#include <iostream>
using namespace std;

//works on divide-conquer principal
//merge sort:worst-average-best is O(logn)
//quickSort:no need for extra space
//quickSort is the same but implementation differ in partitioning
//bestcase O(nlogn) worstcase if array sorted it will not conquer it so O(n2)

int partation1(int arr[],int l,int h)
{
    int p=arr[l];
    int i=l;
    int j=h;
    while(i<j)
    {
        do
        {
            i++;
        }while(i!=h+1&&arr[i]<=p);
        do
        {
            j--;
        }while(arr[j]>p);
        if(i<j)
            swap(arr[i],arr[j]);
    }
    swap(arr[l],arr[j]);
    return j;
}
void Quicksort1(int arr[],int l,int h)//h is end+1 l is start
{
    if(l<h)
    {
        int piv=partation1(arr,l,h);
        Quicksort1(arr,l,piv);
        Quicksort1(arr,piv+1,h);
    }
}
int partation2(int arr[],int iBegin,int iEnd)
{
    int i=iBegin;
    int j=iEnd;
    int pivotLoc=i;
    while(true)
    {
        while(arr[pivotLoc]<=arr[j]&&j!=pivotLoc)
        {
            j--;
        }
        if(pivotLoc==j) break;
        else if(arr[pivotLoc]>arr[j])
        {
            swap(arr[pivotLoc],arr[j]);
            pivotLoc=j;
        }
        while(arr[pivotLoc]>arr[i]&&pivotLoc!=i)
        {
            i++;
        }
        if(pivotLoc==i)
            break;
        else if(arr[pivotLoc]<arr[i])
        {
            swap(arr[i],arr[pivotLoc]);
            pivotLoc=i;
        }
    }
    return pivotLoc;
}
void Quicksort2(int arr[],int l,int r)
{
    if(l<r)
    {
        int piv=partation2(arr,l,r);
        Quicksort2(arr,l,piv-1);
        Quicksort2(arr,piv+1,r);
    }
}
void Quicksort1_test()
{
    int arr[]={3,4,5,6,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    Quicksort1(arr,0,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
void Quicksort2_test()
{
    int arr[]={2,-1,4,7,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    Quicksort2(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

int main()
{
    //Quicksort1_test();
    Quicksort2_test();
    return 0;
}
