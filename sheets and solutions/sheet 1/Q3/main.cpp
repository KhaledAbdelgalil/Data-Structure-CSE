#include <iostream>

using namespace std;
int max_no(int x,int y)
{
  if(x>y) return x;
  else return y;
}
int Max_solution(int arr[],int n)
{
    if(n==1) return arr[0];
    int first=arr[0];
    int second=Max_solution(arr+1,n-1);

    return max_no(first,second);
}


int main()
{
    int arr[]={100,1,2,3,4,1000,2,3,4,523,22,2222};
    int n=12;
    cout<<Max_solution(arr,n);
    return 0;
}
