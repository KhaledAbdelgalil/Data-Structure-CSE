#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
int n,e,u,v,w;

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
        cout<<char(print[i].first.first+65)<<" "<<char(print[i].first.second+65)<<" "<<print[i].second<<endl;
    }
}

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

void dijsktra(int source,vector< list < pair<int,int> > > adj_list,int target)
{
   //distance - current node-parent node
   priority_queue< pair <int , pair <int , int> > ,
    vector< pair< int,pair<int ,int> > >,
    greater< pair < int,pair < int,int > > > > nodes;//distance-node-parent
    vector<int>d(n,INF);
    vector<int>p(n,-1);
    nodes.push({0,{source,source}});
    while(!nodes.empty())
    {
        pair <int , pair <int , int> > q=nodes.top();
        nodes.pop();
        int distance =q.first;
        int current_node=q.second.first;
        int parent_node=q.second.second;
        if(d[current_node]!=INF) continue;
        d[current_node]=distance;
        p[current_node]=parent_node;
        for(list< pair< int,int> >::iterator it=adj_list[current_node].begin();it!=adj_list[current_node].end();it++)
        {
            int next_node=(*it).first;
            int weight=(*it).second;
            if(d[next_node]!=INF)continue;
            nodes.push({distance+weight,{next_node,current_node}});
        }
    }
    cout<<"distance from: "<<char(source+65)<<" till "<<char(target+65)<<" is: "<<d[target]<<endl;
    vector<int>print;
    print.push_back(target);
    while(p[target]!=target)
    {
        print.push_back(p[target]);
        target=p[target];
    }
    cout<<"path is : ";
    for(int i=print.size()-1;i>=0;i--)
        cout<<char(print[i]+65)<<" ";
}

int main()
{
    char uu,vv;
    cout<<"enter no. of nodes and edges"<<endl;
    cin>>n>>e;
    vector< list< pair <int,int> > >adj_list(n);
    vector<vector< int > >adj_matrix(n,vector<int>(n,-1));
    for(int i=0;i<e;i++)
    {
        cin>>uu>>vv>>w;
        adj_matrix[int(uu-65)][int(vv-65)]=w;
        adj_matrix[int(vv-65)][int(uu-65)]=w;
        adj_list[int(uu-65)].push_back({int(vv-65),w});
        adj_list[int(vv-65)].push_back({int(uu-65),w});
    }


    cout<<"enter number of BFS you want to make"<<endl;
    cin>>e;
    char x;
    for(int i=0;i<e;i++)
    {
        cout<<"enter vertex:"<<endl;
        vector<bool>visited(n,0);
        cin>>x;
        BFS(x,adj_matrix,visited,n);
        cout<<endl;
    }
    cout<<"enter random vertex to start from spaning tree"<<endl;
    cin>>x;
    print_MST(adj_list,int(x-'A'));
    cout<<endl<<"enter source and target"<<endl;
    char src,trg;
    cin>>src>>trg;
    dijsktra(int(src-'A'),adj_list,int(trg-'A'));
    return 0;
}
