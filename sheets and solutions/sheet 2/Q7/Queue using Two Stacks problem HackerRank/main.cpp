//this is solution of:https://www.hackerrank.com/challenges/queue-using-two-stacks/problem
#include <iostream>
#include<stack>
using namespace std;

class queue
{
 private:
     stack<int>rear,front;
 public:
    void push(int x)
    {
        rear.push(x);
    }
    int top()
    {
        if(front.empty())
        {
            while(!rear.empty())
            {
                front.push(rear.top());
                rear.pop();
            }
        }
        return front.top();
    }
    void pop()
    {
        if(front.empty())
        {
            while(!rear.empty())
            {
                front.push(rear.top());
                rear.pop();
            }
        }
        front.pop();
    }


};
int main()
{
    int N,Q,num;
    queue q;
    cin>>N;
    while(N--)
    {
        cin>>Q;
        if(Q==1)
        {
            cin>>num;
            q.push(num);
        }
        else if(Q==2) q.pop();
        else
        {
                cout<<q.top()<<endl;
        }
    }
    return 0;
}
