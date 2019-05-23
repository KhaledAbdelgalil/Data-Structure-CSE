//this problem is found @ https://www.hackerrank.com/challenges/maximum-element/problem
//we will keep track of current maximum at every element is added
#include <iostream>
#include<stack>
#include<algorithm>
using namespace std;

stack<int>elements;
stack<int>current_max;
int main()
{
    int N;
    int Q;
    int e;
    cin>>N;
    while(N--)
    {
        cin>>Q;
        if(Q==1)
        {
            cin>>e;
            //cout<<e;
            if(elements.empty())
            {
                elements.push(e);
                current_max.push(e);
            }
            else{
                elements.push(e);
                current_max.push(max(e,current_max.top()));
            }
        }
        else if(Q==2)
        {
            elements.pop();
            current_max.pop();
        }
        else if(Q==3)
        {
            cout<<current_max.top()<<endl;
        }
    }
    return 0;
}
