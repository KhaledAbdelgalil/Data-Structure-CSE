#include <iostream>
using namespace std;
int max_maxHeap(int arr[],int n)
{
    return arr[0];
}
int min_maxHeap(int arr[],int n)
{
    //we know that min is found at leaves but we don't know where
    //so start searching from leaves
    if(n==1) return arr[0];
    int minn=arr[(n-2)/2+1];
    for(int i=(n-2)/2+2;i<n;i++)
    {
        minn=min(arr[i],minn);
    }
    return minn;
}
int main()
{
    int arr1[]={100,65,45,30,28,23,7,5,1};
    cout<<"max is: "<<max_maxHeap(arr1,9)<<endl;
    cout<<"min is: "<<min_maxHeap(arr1,9)<<endl;
    cout<<"now your inputs enter number of nodes followed by n nodes spaced"<<endl;
    int n;
    cin>>n;
    int* arr2=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr2[i];
    cout<<"max is: "<<max_maxHeap(arr2,n)<<endl;
    cout<<"min is: "<<min_maxHeap(arr2,n)<<endl;
    delete []arr2;
    return 0;
}
//advantages of heap
//fast all operations work in o(logn) even getMax works in O(1)
//space efficient
//easy to implement in few lines of code
