//important Link:://https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
int n,e;

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
        cout<<endl;
}

int main()
{
    //0-A 1-B 2-C 3-D 4-E 5-F 6-G

    cin>>n>>e;
    int x,y,w;
    vector< list<pair <int,int> > > adj_list(n);
    for(int i=0;i<e;i++)
    {
        cin>>x>>y>>w;
        adj_list[x].push_back({y,w});
        adj_list[y].push_back({x,w});
    }
    cout<<"dijsktra on A-F :"<<endl;
    dijsktra(0,adj_list,5);
    cout<<"dijsktra on C-G :"<<endl;
    dijsktra(2,adj_list,6);
    return 0;
}
