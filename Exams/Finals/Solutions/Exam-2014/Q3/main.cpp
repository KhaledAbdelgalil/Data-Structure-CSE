#include <iostream>
#include <stack>
using namespace std;
void recur(stack<int>s)
{
if(!s.empty())
{
    int x=s.top();
    s.pop();
    cout<<x<<"\t";
    recur(s);
    s.push(x);
}
}
int main()
{
    stack<int>a;
    a.push(10);
    a.push(3);
    a.push(26);
    a.push(5);
    recur(a);
    return 0;
}
