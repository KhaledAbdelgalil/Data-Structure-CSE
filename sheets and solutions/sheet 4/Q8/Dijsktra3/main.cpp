//important Link:://https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
#include <bits/stdc++.h>
using namespace std;
#define n 9
#define INF 100000000

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
}

int main()
{
    vector< list<pair <int,int> > > adj_list(n);
    adj_list[0].push_back(make_pair(1,4));
    adj_list[0].push_back({7,8});

    adj_list[1].push_back({0,4});
    adj_list[1].push_back({7,11});
    adj_list[1].push_back({2,8});

    adj_list[2].push_back({1,8});
    adj_list[2].push_back({8,2});
    adj_list[2].push_back({5,4});
    adj_list[2].push_back({3,7});

    adj_list[3].push_back({2,7});
    adj_list[3].push_back({5,14});
    adj_list[3].push_back({4,9});

    adj_list[4].push_back({3,9});
    adj_list[4].push_back({5,10});

    adj_list[5].push_back({4,10});
    adj_list[5].push_back({3,14});
    adj_list[5].push_back({2,4});
    adj_list[5].push_back({6,2});

    adj_list[6].push_back({5,2});
    adj_list[6].push_back({8,6});
    adj_list[6].push_back({7,1});

    adj_list[7].push_back({6,1});
    adj_list[7].push_back({0,8});
    adj_list[7].push_back({8,7});
    adj_list[7].push_back({1,11});

    adj_list[8].push_back({2,2});
    adj_list[8].push_back({6,6});

    dijsktra(0,adj_list,8);

    return 0;
}
