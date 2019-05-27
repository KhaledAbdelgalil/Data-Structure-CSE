#include <bits/stdc++.h>
using namespace std;
//A:0 B:1 C:2 D:3 E:4 F:5
void BFS(char source,vector<vector< int > >adj_matrix,vector<bool>&visited,int n)
{
    int src=int(source-'A');
    queue<int>q;
    q.push(src);
    visited[src]=1;
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        cout<<char(f+65)<<" ";
        for(int i=0;i<n;i++)
        {
            if(adj_matrix[f][i]!=-1&&visited[i]==0)
            {
                visited[i]=1;
                q.push(i);
            }
        }
    }
}

void dfs(int source,vector<vector< int > >adj_matrix,vector<bool>&visited,int n)
{
    visited[source]=1;

        for(int j=0;j<n;j++)
        {
            if(adj_matrix[source][j]!=1&&visited[j]!=1)
            {
                dfs(j,adj_matrix,visited,n);
            }
        }

}
bool isConnected(vector<vector< int > >adj_matrix,vector<bool>&visited,int n)
{
    dfs(0,adj_matrix,visited,n);
    for(int i=0;i<visited.size();i++)
    {
        if(visited[i]==0) return 0;
    }
    return 1;
}
int main()
{
    int n,e,u,v,w;
    char uu,vv;
    cout<<"enter no. of nodes and edges"<<endl;
    cin>>n>>e;
    vector<vector< int > >adj_matrix(n,vector<int>(n,-1));
    for(int i=0;i<e;i++)
    {
        cin>>uu>>vv>>w;
        adj_matrix[int(uu-65)][int(vv-65)]=w;
        adj_matrix[int(vv-65)][int(uu-65)]=w;
    }
    cout<<"  ";
    for(int i=0;i<n;i++)
        cout<<char(i+65)<<"  ";
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<char(65+i)<<"  ";
        for(int j=0;j<n;j++)
        {
            if(adj_matrix[i][j]!=-1)
            cout<<adj_matrix[i][j]<<"  ";
            else cout<<"   ";
        }
        cout<<endl;
    }

    vector<bool>vis(n,0);
    if(isConnected(adj_matrix,vis,n)) cout<<"Connected Graph"<<endl;
    else cout<<"Disconnected Graph"<<endl;

    cout<<"enter number of BFS you want to make"<<endl;
    cin>>n;
    char x;
    for(int i=0;i<n;i++)
    {
        vector<bool>visited(n,0);
        cin>>x;
        BFS(x,adj_matrix,visited,n);
        cout<<endl;
    }
    return 0;
}
