#include <iostream>
using namespace std;
//works on divide-and-Conquer
//O(nlogn)
//Merge function its complexity is O(n)
int count3=0;
void merge(int arr[],int l,int m,int r,int &count2)
{
    int i,j,k;
    int n1=m-l+1;//divide array into left and right ,take this element if odd numbers found in array  to left sub array [0---m]
    int n2=r-m;
    int *L=new int[n1];
    int *R=new int[n2];

    for(i=0;i<n1;i++)
        L[i]=arr[l+i];
    for(j=0;j<n2;j++)
        R[j]=arr[m+1+j];
    i=j=0;
    k=l;
    while(i<n1&&j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
            count3++;
        }
        else
        {
            arr[k]=R[j];
            j++;
            count3++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int l,int r,int &count,int &count2)
{
        if(l<r)
        {
            int m=l+(r-l)/2;
            mergeSort(arr,l,m,++count,count2);
            mergeSort(arr,m+1,r,++count,count2);
            merge(arr,l,m,r,++count2);
        }
}
//mergeSort:TimeComplexity:O(nlogn),spaceComplexity:O(n) but insertion-selection-bubble works on in-place principle//mergeSort is used with linkedList
int main()
{
    int count=0;
    int count2=0;
    int arr[]={29,10,14,37,13};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1,count,count2);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl<<"Counting of mergeSort: "<<count<<endl;
    cout<<endl<<"Counting of mergeCalls: "<<count2<<endl;
    cout<<endl<<"NO of actual comparisons: "<<count3<<endl;
    return 0;
}
