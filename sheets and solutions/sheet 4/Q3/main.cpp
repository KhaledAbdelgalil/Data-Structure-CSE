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

//0->A 1 B 2 C 3:D 4:E 5:F 6:G   dfs: 3 0 1 2 4 5 6 , bfs: 3 0 4 6 1 5 2
int main()
{
    //D
    adj_list[3].push_back(0);
    adj_list[3].push_back(4);
    adj_list[3].push_back(6);
    //A
    adj_list[0].push_back(3);
    adj_list[0].push_back(1);
    //B
    adj_list[1].push_back(2);
    adj_list[1].push_back(4);
    adj_list[1].push_back(0);
    //C
    adj_list[2].push_back(1);
    //E
    adj_list[4].push_back(1);
    adj_list[4].push_back(5);
    adj_list[4].push_back(3);
    //G
    adj_list[6].push_back(3);
    //F
    adj_list[5].push_back(4);
    dfs(5);
    return 0;
}
