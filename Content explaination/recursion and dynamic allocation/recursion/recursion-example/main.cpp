#include<iostream>
using namespace std;

double factorial(int n)
{
        if(n<=1) return 1;

        cout<<"getting factorial of "<<n<<endl;
	  int temp=n*factorial(n-1);
        cout<<"done calculating factorial of "<<n<<endl;

	  return temp;
}
//base case array contains 1 element so sum is that element i.e arr[0]
//general rule sum=arr[0]+sum of rest of array i,e arr[0]+sum(arr+1,n-1); sum(arr[0:end])=arr[0]+sum(arr[1:end]);
int sum_rec(int arr[],int n)
{
    if(n==1) return arr[0];

    int part1=arr[0];
    int part2=sum_rec(arr+1,n-1);
    return part1+part2;
}

int main(){
    int n;
    cin>>n;
    int *arr=new int(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"example 1 recursion:"<<endl;
	cout<<factorial(5)<<endl;
    cout<<"example 2 recursion:"<<endl;
    //getting sum of array using recursion
    cout<<sum_rec(arr,n);
	return 0;
    }
