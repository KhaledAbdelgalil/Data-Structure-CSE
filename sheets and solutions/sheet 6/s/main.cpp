#include <bits/stdc++.h>

using namespace std;

vector< list<int> > adj_list(7);
vector<bool>visited(7,0);
void dfs(int source)
{
    visited[source]=true;
    cout<<source<<" ";

    for(list<int>::iterator it=adj_list[source].begin();it!=adj_list[source].end();it++)
    {
        if(!visited[*it]) dfs(*it);
    }
}
void BFS(int source)
{
    visited[source]=true;
    queue<int>q;
    q.push(source);
    while(!q.empty())
    {
        int f=q.front();
        cout<<f<<" ";
        for(list<int>::iterator it=adj_list[f].begin();it!=adj_list[f].end();it++)
        {
            if(!visited[*it]){
                q.push(*it);
                visited[*it]=true;
            }
        }
        q.pop();
    }
}

int main()
{
    //0
    adj_list[0].push_back(1);
    adj_list[0].push_back(2);
    //1
    adj_list[1].push_back(0);
    //2
    adj_list[2].push_back(3);
    adj_list[2].push_back(0);
    //3
    adj_list[3].push_back(2);
    dfs(0);

    return 0;
}
