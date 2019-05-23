#include <iostream>

using namespace std;

long long power1(long long x,long long n)
{
    if(n==0) return 1;

    return x*power1(x,n-1);
}
long long power2(long long x,long long n)
{
    if(n==0) return 1;
    if(n==1) return x;
    if(n%2==0)
        return power2(x*x,n/2);
    return power2(x*x,n/2)*x;
}

int main()
{
    cout<<power1(2,7)<<" "<<power2(2,7);
    return 0;
}
