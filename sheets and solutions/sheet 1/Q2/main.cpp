#include <iostream>
using namespace std;
bool solution_unsorted(int arr[],int n)//O(n2) 1+2+3+......+n=n(n+1)/2 i.e O(n2)
{
    for(int i=0;i<n-1;i++)//n-1 because you take element and compare with all elements after it //1 assigmnet n comparisons n-1 increments
    {
        for(int j=i+1;j<n;j++)//(n-1)*1 assigment +n+n-1+n-2+n-3+n-4+----+1=n(n+1)/2 comparisons + approximate same increments
        {
            if(arr[i]==arr[j]) return true;
        }
    }
    return false;
}
//T(n)=1+n*c+c+(n-1)+n*(n-1)=O(n2)
bool solution_sorted(int arr[],int n)//O(n)
{
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]==arr[i+1]) return true;
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    int* arr=new int(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    //solution_unsorted(arr,n)==true?cout<<"YES":cout<<"NO";
    solution_sorted(arr,n)==true?cout<<"YES":cout<<"NO";
    return 0;
}
