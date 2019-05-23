#include <iostream>
using namespace std;
void SelectionSort(int arr[],int n)//Time complexity:averageCase:O(n^2) and worstCase:O(n^2)//Space Complexity no need for extra space O(1)
{
    int minIndx;
    for(int i=0;i<n-1;i++)//pass on all elements except last one will be already sorted
    {
        minIndx=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minIndx])
                minIndx=j;
        }
        swap(arr[i],arr[minIndx]);
    }

}
int main()
{
    int arr[]={60,40,50,30,10,20};
    int n=sizeof(arr)/sizeof(arr[0]);
    SelectionSort(arr,n);
    for(int i=0;i<6;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
