//prim's:grow connected graph:repeatedly attach a new vertex to the current tree by a lightest edge
//Kruskal's algorithm::repeatedly add the next lightest edge if this doesn't produce a cycle
#include <bits/stdc++.h>
using namespace std;
void print_MST(vector< list< pair <int,int> > >adj_list,int random)
{
    int n=adj_list.size();
    vector<bool>vis(n,0);
    vis[random]=1;//start at random element
    vector< pair< pair<int,int>,int > >print;
    priority_queue<pair< pair<int,int>,int >,vector < pair< pair<int,int>,int > >,greater<pair< pair<int,int>,int > > >q ;
    for(list< pair <int,int> >::iterator it=adj_list[random].begin();it!=adj_list[random].end();it++)
    {
        pair<int,int>s=*it;
        q.push({{s.second,s.first},random});
    }
    long long cost=0;
    while(!q.empty())
    {
        int w=q.top().first.first;
        int node=q.top().first.second;
        int parent=q.top().second;
        q.pop();
        if(vis[node]) continue;
        vis[node]=true;
        cost+=w;
        print.push_back({{parent,node},w});
        for(list< pair <int,int> >::iterator it=adj_list[node].begin();it!=adj_list[node].end();it++)
        {
            pair<int,int>s=*it;
            q.push({{s.second,s.first},node});
        }
    }
    cout<<"cost of spanning tree is : "<<cost<<endl;
    cout<<"edges:"<<endl;
    for(int i=0;i<print.size();i++)
    {
        cout<<print[i].first.first<<" "<<print[i].first.second<<" "<<print[i].second<<endl;
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    int u,v,w;
    vector< list< pair <int,int> > >adj_list(n);
    for(int i=0;i<e;i++)
    {
        cin>>u>>v>>w;
        adj_list[u].push_back({v,w});
        adj_list[v].push_back({u,w});
    }
    cout<<"enter random vertex:";
    cin>>w;
    print_MST_Cost(adj_list,w);
    return 0;
}
