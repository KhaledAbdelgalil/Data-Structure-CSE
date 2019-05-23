#include <iostream>
using namespace std;
//takes advantage of mergeSort,advantage of insertionSort
//time complexity of mergeSort O(nlogn)//spaceComplexity O(1)
void heapify(int arr[],int n,int i)//O(logn)
{
    int l=2*i+1;
    int r=2*i+2;
    int max=i;
    if(l<n&&arr[l]>arr[max])
        max=l;
    if(r<n&&arr[r]>arr[max])
        max=r;
    if(max!=i)
    {
        swap(arr[i],arr[max]);
        heapify(arr,n,max);
    }
}
void buildHeap(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
}
void HeapSort(int arr[],int n)
{
    buildHeap(arr,n);//O(n)
    for(int i=n-1;i>=0;i--)//O(nlogn)
    {
        swap(arr[0],arr[i]);//extract first max element put it at last_place
        heapify(arr,i,0);//heapfiy from zero with size less than by 1
    }

    //O(n)+O(nlogn)=O(nlogn)
int main()
{
    int arr[]={90,10,40,70,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    HeapSort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
