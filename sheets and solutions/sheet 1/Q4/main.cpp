#include <bits/stdc++.h>

using namespace std;
//the thing that you are sure with that the biggest element will be at the right after the iteration

//you need to make n-1 iterations as if we have 11 elements after 1 iteration we are sure that last element is in its place ,after 10 iterations the right 10 elments are sorted so first is sorted so no need to iterate n iterations
void b_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        bool sorted=true;
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j+1]<arr[j])
            {
                swap(arr[j+1],arr[j]);
                sorted=false;
            }
        }
        if(sorted) break;
    }
}
int main()
{
    int arr[]={8,7,6,5,4,3,2,1};
    b_sort(arr,8);
    for(int i=0;i<8;i++)
        cout<<arr[i]<<" ";
    return 0;
}
