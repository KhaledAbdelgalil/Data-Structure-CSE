//problem::https://www.hackerrank.com/challenges/minimum-average-waiting-time/problem
#include <bits/stdc++.h>
using namespace std;

void Minimum_Average_Waiting_Time_Solution()
{
    int n;
    cin>>n;
    int x,y;
    priority_queue< pair<int,int>,vector <pair<int,int> >,greater< pair <int,int> > > arrivalTime;
    priority_queue< pair<int,int>,vector <pair<int,int> >,greater< pair <int,int> > > burstTime;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        arrivalTime.push({x,y});
    }
    unsigned long long currentTime=arrivalTime.top().first;
    unsigned long long averageWaitingTime=0;
    while(!arrivalTime.empty())
    {
        while(!arrivalTime.empty()&&arrivalTime.top().first<=currentTime)
        {
            pair<int,int>q=arrivalTime.top();
            arrivalTime.pop();
            burstTime.push({q.second,q.first});
        }
        if(!burstTime.empty())
        {
        pair<int,int>q=burstTime.top();
        burstTime.pop();
        averageWaitingTime+=q.first+currentTime-q.second;
        currentTime+=q.first;
        }
        else currentTime++;

    }
    while(!burstTime.empty())
    {

        pair<int,int>q=burstTime.top();
        burstTime.pop();
        averageWaitingTime+=q.first+currentTime-q.second;
        currentTime+=q.first;
    }
    cout<<averageWaitingTime/n;
}


int main()
{
    Minimum_Average_Waiting_Time_Solution();
    return 0;
}
