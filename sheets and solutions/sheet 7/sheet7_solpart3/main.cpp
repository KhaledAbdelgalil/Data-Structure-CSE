#include <iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
#define INF 10000000
int n=7,e=12;
vector<list <pair <int,int> > >adj_list(n);



int dijsktra(int source)
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
    int temp=0;
    cout<<char(source+65)<<"  ";
    for(int i=0;i<n;i++)
    {
        cout<<d[i]<<" ";
        temp+=d[i];
    }
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
    cout<<"Solution of Part11,12,13"<<endl;
    dijsktra(0);
    dijsktra(1);
    dijsktra(2);
    dijsktra(3);
    dijsktra(4);
    dijsktra(5);
    dijsktra(6);

    return 0;
}
