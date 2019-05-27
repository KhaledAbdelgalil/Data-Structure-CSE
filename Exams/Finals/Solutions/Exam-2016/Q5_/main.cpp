#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

void dijsktra(int source,vector< list < pair<int,int> > > adj_list,int target)
{
   //distance - current node-parent node
   priority_queue< pair <int , pair <int , int> > ,
    vector< pair< int,pair<int ,int> > >,
    greater< pair < int,pair < int,int > > > > nodes;//distance-node-parent
    vector<int>d(11,INF);
    vector<int>p(11,-1);
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
    cout<<"distance from: "<<source<<" till "<<target<<" is: "<<d[target]<<endl;
    vector<int>print;
    print.push_back(target);
    while(p[target]!=target)
    {
        print.push_back(p[target]);
        target=p[target];
    }
    cout<<"path is : ";
    for(int i=print.size()-1;i>=0;i--)
        cout<<print[i]<<" ";
}


void dfs(int src,int&max_index,vector<bool>&vis,vector< list <pair<int,int> > >adj_list,vector<int>data)
{
    vis[src]=1;
    if(data[src]>data[max_index]) max_index=src;
    for(list< pair <int,int> >::iterator it=adj_list[src].begin();it!=adj_list[src].end();it++)
    {
        int i=(*it).first;
        if(vis[i]!=1)
        {
            dfs(i,max_index,vis,adj_list,data);
        }
    }
}
int max_index(vector< list <pair<int,int> > >adj_list,vector<int>data)
{
    vector<bool>vis(11,0);

    int max_=0;

    dfs(0,max_,vis,adj_list,data);
    return max_;
}
void print_MST(vector< list< pair <int,int> > >adj_list,int random)
{
    vector<bool>vis(11,0);
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
void init(vector< list <pair<int,int> > >&adj_list)
{
        adj_list[0].push_back({1,8});
        adj_list[0].push_back({10,3});
        adj_list[0].push_back({7,10});
        adj_list[0].push_back({8,6});
        adj_list[0].push_back({9,12});

        adj_list[1].push_back({0,8});
        adj_list[1].push_back({10,7});
        adj_list[1].push_back({2,10});
        adj_list[1].push_back({4,2});


        adj_list[2].push_back({10,5});
        adj_list[2].push_back({3,9});
        adj_list[2].push_back({1,10});

        adj_list[3].push_back({5,12});
        adj_list[3].push_back({2,9});
        adj_list[3].push_back({13,4});

        adj_list[4].push_back({1,2});
        adj_list[4].push_back({6,6});
        adj_list[4].push_back({3,13});
        adj_list[4].push_back({5,10});

        adj_list[5].push_back({6,8});
        adj_list[5].push_back({4,10});
        adj_list[5].push_back({3,12});

        adj_list[6].push_back({7,7});
        adj_list[6].push_back({0,9});
        adj_list[6].push_back({4,6});
        adj_list[6].push_back({5,8});

        adj_list[7].push_back({6,7});
        adj_list[7].push_back({0,10});
        adj_list[7].push_back({8,3});

        adj_list[8].push_back({7,3});
        adj_list[8].push_back({0,6});
        adj_list[8].push_back({9,10});


        adj_list[9].push_back({8,10});
        adj_list[9].push_back({0,12});
        adj_list[9].push_back({10,8});

        adj_list[10].push_back({9,8});
        adj_list[10].push_back({0,3});
        adj_list[10].push_back({1,7});
         adj_list[10].push_back({2,5});



}

int main()
{
    vector< list <pair<int,int> > >adj_list(11);
     adj_list[0].push_back({1,8});
        adj_list[0].push_back({10,3});
        adj_list[0].push_back({7,10});
        adj_list[0].push_back({8,6});
        adj_list[0].push_back({9,12});

        adj_list[1].push_back({0,8});
        adj_list[1].push_back({10,7});
        adj_list[1].push_back({2,10});
        adj_list[1].push_back({4,2});


        adj_list[2].push_back({10,5});
        adj_list[2].push_back({3,9});
        adj_list[2].push_back({1,10});

        adj_list[3].push_back({5,12});
        adj_list[3].push_back({2,9});
        adj_list[3].push_back({13,4});

        adj_list[4].push_back({1,2});
        adj_list[4].push_back({6,6});
        adj_list[4].push_back({3,13});
        adj_list[4].push_back({5,10});

        adj_list[5].push_back({6,8});
        adj_list[5].push_back({4,10});
        adj_list[5].push_back({3,12});

        adj_list[6].push_back({7,7});
        adj_list[6].push_back({0,9});
        adj_list[6].push_back({4,6});
        adj_list[6].push_back({5,8});

        adj_list[7].push_back({6,7});
        adj_list[7].push_back({0,10});
        adj_list[7].push_back({8,3});

        adj_list[8].push_back({7,3});
        adj_list[8].push_back({0,6});
        adj_list[8].push_back({9,10});


        adj_list[9].push_back({8,10});
        adj_list[9].push_back({0,12});
        adj_list[9].push_back({10,8});

        adj_list[10].push_back({9,8});
        adj_list[10].push_back({0,3});
        adj_list[10].push_back({1,7});
         adj_list[10].push_back({2,5});
    /*vector<int>data(11);

    for(int i=0;i<n;i++)
    {
        cin>>data[i];
    }
    int u,v,w;
    for(int i=0;i<e;i++)
    {
        cin>>u>>v>>w;
        adj_list[u].push_back({v,w});
        adj_list[v].push_back({u,w});
    }
    //cout<<max_index(adj_list,data);*/

    //print_MST(adj_list,4);
    int des;
    for(int i=0;i<11;i++)
    {
    cout<<"this dijkstra made from node 10"<<endl;
    cin>>des;
    dijsktra(10,adj_list,des);
    }
    return 0;
}
