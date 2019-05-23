#include <bits/stdc++.h>
using namespace std;
#define INF 10000000
int n=9;
void Bellman_ford(int source,vector<list < pair <int,int> > >adj_list,int target)
{
    vector<int>d(n,INF);
    vector<int>p(n,-1);
    d[source]=0;
    p[source]=source;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
            for(list < pair <int,int> >::iterator it=adj_list[j].begin();it!=adj_list[j].end();it++)
            {
                pair<int,int>q=*it;
                int v=q.first;
                int w=q.second;
                if(d[j]+w<d[v])
                {
                    d[v]=d[j]+w;
                    p[v]=j;
                }
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
void Testing1()
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

    Bellman_ford(0,adj_list,4);

}
int main()
{
    //Testing1();
    int e;
    cin>>n>>e;
    vector< list<pair<int ,int> > >q(n);
    int u,v,w;
    for(int i=0;i<e;i++)
    {
        cin>>u>>v>>w;
        q[u].push_back({v,w});
    }
    int src,target;
    cin>>src>>target;
    Bellman_ford(src,q,target);
    return 0;
}

