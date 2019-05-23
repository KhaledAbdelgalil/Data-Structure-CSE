#include <bits/stdc++.h>
using namespace std;
int n,m;

void dfs_isCyclic(int source,vector< list<int> >&courses,vector<int>&start,vector<int>&finish,bool&c)
{
    start[source]=1;
    for(list<int>::iterator it=courses[source].begin();it!=courses[source].end();it++)
    {
        int child=*it;
        if(start[child]==-1) //not visited yet
            dfs_isCyclic(child,courses,start,finish,c);
        else if(finish[child]==-1) c=true;//visit who discovers me
    }
    finish[source]=1;
}
int main()
{
    cin>>n>>m;
    int x,y;
    vector< list<int> >courses(n);
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        courses[x].push_back(y);
    }
    vector<int>start(n,-1);
    vector<int>finish(n,-1);
    bool c=0;//no cycle assume good case
    dfs_isCyclic(0,courses,start,finish,c);
    if(c==true) cout<<"there is a cycle";
    else cout<<"not a cyclic";
    return 0;
}
