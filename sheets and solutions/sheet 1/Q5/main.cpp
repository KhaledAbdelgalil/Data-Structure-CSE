#include <iostream>
using namespace std;

double factorial(int n)
{
    if(n<=1) return 1;
    return n*factorial(n-1);
}
//summation tends to e
int main()
{
    int n;
    cin>>n;
    double* arr=new double(n);
    double sum=0;
    for(int i=0;i<n;i++)
    {
        arr[i]=1.0/factorial(i);
        sum+=arr[i];
    }
    /*
    arr[0]=1;
    arr[1]=1;
    sum=2;
    for(int i=2;i<n;i++)
    {
        arr[i]=arr[i-1]/i;
        sum+=arr[i];
    }
    */
    cout<<sum<<endl;
    return 0;
}
