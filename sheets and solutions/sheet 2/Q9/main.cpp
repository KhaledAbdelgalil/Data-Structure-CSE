#include<iostream>
#include <queue>
using namespace std;
void Q9_reverse_queue(queue<int> &q)//should be by reference
{
    if(q.size()==0) return;
    int top=q.front();
    q.pop();
    Q9_reverse_queue(q);
    q.push(top);
}
int main()
{
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    Q9_reverse_queue(q);
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}
