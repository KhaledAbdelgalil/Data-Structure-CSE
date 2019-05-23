//It is easy for undirected graph, we can just do a BFS and DFS starting from any vertex. If BFS or DFS visits all vertices,
// then the given undirected graph is connected
#include <bits/stdc++.h>
using namespace std;
int n,m;
void dfs(vector<list <int> > &adj_list,vector<bool> &visited,int source)
{
    visited[source]=true;
    for(list<int>::iterator it=adj_list[source].begin();it!=adj_list[source].end();it++)
    {
        if(!visited[*it]) {
            dfs(adj_list,visited,*it);
        }
    }
}
bool is_connected_or_not(vector<list <int> > &adj_list)
{
    vector<bool>visited(n,0);
    int source=0;
    dfs(adj_list,visited,source);
    for(int i=0;i<n;i++)
    {
        if(!visited[i]) return false;
    }
    return true;
}

void Testing()
{
    cin>>n>>m;
    vector< list<int> >adj_list(n);
    int x,y;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
    if(is_connected_or_not(adj_list)) cout<<"Connected";
    else cout<<"Not connected";
}
int main()
{

    Testing();
    return 0;
}
