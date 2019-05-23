//problem::https://codeforces.com/contest/937/problem/B
//problem::https://www.hackerrank.com/challenges/jesse-and-cookies/problem
//problem::https://www.hackerrank.com/challenges/find-the-running-median/problem
#include <bits/stdc++.h>

using namespace std;
void Vile_Grasshoppers_Solution()
{
    int p,y;
    cin>>p>>y;
    for(int i=y;i>p;i--)
    {
        int flag=1;
        for(int j=2;j*j<=y&&j<=p;j++)//j*j as if one grasshopper is at 4 so 4*2 is seen from 2*4 no need to calculate it again
        {
            if(i%j==0)
            {
                flag=0;
                break;
            }
        }
        if(flag) { cout<<i;return;}
    }

    cout<<-1;
}


void Jesse_and_Cookies_Solution()
{
    int n,k;
    cin>>n>>k;
    int x;
    priority_queue< int,vector< int >,greater< int > >q;
    while(n--)
    {
        cin>>x;
        q.push(x);
    }
    int operations=0;
    while(q.size()!=1&&q.top()<k)
    {
        int f=q.top();
        q.pop();
        int s=q.top();
        q.pop();
        q.push(f+2*s);
        operations++;
    }
    if(q.top()>=k)cout<<operations;
    else cout<<-1;
}

void find_the_running_median_Solution()
{
    int n;
    cin>>n;
    priority_queue< int,vector< int >,greater< int > >min_heap;
    priority_queue<int>max_heap;
    int x;

    for(int i=0;i<n;i++)
    {
        cin>>x;
        //adding
        if( !max_heap.empty()&&x <= max_heap.top() )
            max_heap.push(x);
        else min_heap.push(x);
        if(max_heap.size()-min_heap.size()>1||min_heap.size()-max_heap.size()>1)
        {
            if(min_heap.size()>max_heap.size())
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
            else
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
        }
        cout.precision(1000);
        if(max_heap.size()==min_heap.size())
        {
            double ret=0;
            ret+=max_heap.top();
             ret+=min_heap.top();
            cout<<double(ret)/2.0<<endl;
        }
        else
        {
            if(max_heap.size()>min_heap.size())
               cout<<max_heap.top()<<endl;
            else cout<<min_heap.top()<<endl;
        }
    }
}
int main()
{
    //Vile_Grasshoppers_Solution();
    //Jesse_and_Cookies_Solution();
    find_the_running_median_Solution();
    return 0;
}
