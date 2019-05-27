#include <iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
#define INF 10000000
int n=7,e=12;
vector<list <pair <int,int> > >adj_list(n);

void print_MST(int random)
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

        cout<<char(65+print[i].first.first)<<" "<<char(65+print[i].first.second)<<" "<<print[i].second<<endl;
    }
}

int dijsktra(int source,int target)
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
    int temp=d[target];
    print.push_back(target);
    while(p[target]!=target)
    {
        print.push_back(p[target]);
        target=p[target];
    }
    cout<<"path is : ";
    for(int i=print.size()-1;i>=0;i--)
        cout<<char(print[i]+65)<<" ";
    cout<<endl;
    return temp;
}


void initialize()
{
    adj_list[int('A'-'A')].push_back({int('B'-'A'),10});
    adj_list[int('A'-'A')].push_back({int('F'-'A'),6});
    adj_list[int('A'-'A')].push_back({int('G'-'A'),6});

    ////////////////////////////
    adj_list[int('B'-'A')].push_back({int('A'-'A'),10});
    adj_list[int('B'-'A')].push_back({int('F'-'A'),8});
    adj_list[int('B'-'A')].push_back({int('E'-'A'),3});
    adj_list[int('B'-'A')].push_back({int('C'-'A'),4});
    ///////////////////////////
    adj_list[int('C'-'A')].push_back({int('B'-'A'),4});
    adj_list[int('C'-'A')].push_back({int('E'-'A'),3});
    adj_list[int('C'-'A')].push_back({int('D'-'A'),5});
    //////////////////////////
    adj_list[int('D'-'A')].push_back({int('G'-'A'),7});
    adj_list[int('D'-'A')].push_back({int('F'-'A'),5});
    adj_list[int('D'-'A')].push_back({int('E'-'A'),4});
    adj_list[int('D'-'A')].push_back({int('C'-'A'),5});
    /////////////////////////
    adj_list[int('E'-'A')].push_back({int('B'-'A'),3});
    adj_list[int('E'-'A')].push_back({int('D'-'A'),4});
    adj_list[int('E'-'A')].push_back({int('C'-'A'),3});
    ////////////////////////
    adj_list[int('F'-'A')].push_back({int('A'-'A'),6});
    adj_list[int('F'-'A')].push_back({int('B'-'A'),8});
    adj_list[int('F'-'A')].push_back({int('D'-'A'),5});
    adj_list[int('F'-'A')].push_back({int('G'-'A'),1});
    ////////////////////////
    adj_list[int('G'-'A')].push_back({int('F'-'A'),1});
    adj_list[int('G'-'A')].push_back({int('A'-'A'),6});
    adj_list[int('G'-'A')].push_back({int('D'-'A'),7});
}






int main()
{
    initialize();
    cout<<"Solution of Part9&&10"<<endl;
    cout<<"if we apply dijkstra(A,D) && and dijkstra(B,D) and find difference between these two costs and then apply min spanning Tree from A and find cost of reaching B till D and from A till D and subtract it will be that difference"<<endl;
    int costA=dijsktra(int('A'-'A'),int('D'-'A'));
    int costB= dijsktra(int('B'-'A'),int('D'-'A'));
    cout<<"diffrence is: "<<costA-costB<<endl;
    print_MST(0);
    return 0;
}
