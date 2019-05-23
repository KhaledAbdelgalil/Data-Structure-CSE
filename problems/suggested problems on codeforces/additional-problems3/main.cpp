//problem::https://codeforces.com/problemset/problem/931/A
//problem::https://codeforces.com/problemset/problem/427/B
//problem::https://codeforces.com/problemset/problem/548/A
//problem::https://codeforces.com/problemset/problem/716/A
//problem::https://codeforces.com/problemset/problem/707/B//take care if many different roads between same two cities take min also take care not to choose city have storage on it
#include <bits/stdc++.h>
using namespace std;

void Prison_Transfer_solution()
{
    int n,t,c;
    cin>>n>>t>>c;
    int x;
    int counter=0;
    int out=0;
    while(n--)
    {
        cin>>x;
        if(x<=t) counter++;
        else counter=0;
        if(counter==c)
        {
            counter--;
            out++;
        }
    }
    cout<<out;
}

void Friends_Meeting()
{
    int x,y;
    cin>>x>>y;
    int diff=abs(x-y);
    int i=1;
    int out=0;
    for(i=1;i<=diff/2;i++)
    {
        out+=i;
    }
    diff%2==0?cout<<out*2:cout<<out*2+i;
}

void Mike_and_Fax()
{
    string s;
    int k;
    cin>>s>>k;
    if(s.size()%k!=0){cout<<"NO";return;}
    int size=s.size()/k;
    int l=0;
    for(int i=1;i<=k;i++)
    {
        int f=0;
        for(int j=0;j<=size/2;j++)
        {
            if(s[j+l]!=s[size*i-1-f]) {cout<<"NO";return;}
            f++;
        }
        l+=size;
    }
    cout<<"YES";
}


void Crazy_Computer_solution()
{
    int n,c;
    cin>>n>>c;
    int counter=0;
    int x1;
    cin>>x1;
    int x2;
    counter++;
    n--;
    while(n--)
    {
        cin>>x2;
        if(x2-x1>c) counter=1;
        else counter++;
        x1=x2;
    }
    cout<<counter;
}


void Bakery_solution()
{
    int n,m,k;
    cin>>n>>m>>k;
    int u,v,w;
    vector< list < pair < int,int > > > adj_list(n);
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
       adj_list[u-1].push_back(make_pair(v-1,w));
        adj_list[v-1].push_back(make_pair(u-1,w));
    }
    int minn=INT_MAX;
    vector<int>storage_index(k);
    vector<bool>storage(n,false);
    for(int i=0;i<k;i++)
    {
        cin>>storage_index[i];
        storage_index[i]--;
        storage[storage_index[i]]=true;
    }
    for(int i=0;i<k;i++)
    {
        for(list< pair<int,int> >::iterator j=adj_list[storage_index[i]].begin();j!=adj_list[storage_index[i]].end();j++)
        {
            pair<int,int>temp=*j;

            if(!storage[temp.first])
            {
                minn=min(temp.second,minn);
            }
        }
    }
    minn==INT_MAX?cout<<-1:cout<<minn;
}


int main()
{
    //Prison_Transfer_solution();
    //Friends_Meeting();
   // Mike_and_Fax();
    Bakery_solution();
    return 0;
}
