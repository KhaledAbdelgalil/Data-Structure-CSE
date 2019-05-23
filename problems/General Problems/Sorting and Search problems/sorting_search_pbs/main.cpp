//1st problem(icecream-parlor):https://www.hackerrank.com/challenges/icecream-parlor/problem
//2nd problem(B. Interesting drink):https://codeforces.com/problemset/problem/706/B
//3rd problem(B. Worms):https://codeforces.com/problemset/problem/474/B
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
void ICE_cream_parlor_solutionn()
{
    int t;
    cin>>t;
    int n,m;
    while(t--)
    {
        cin>>m>>n;
        vector<int>in(n);
        for(int i=0;i<n;i++)
            cin>>in[i];
            int x,y;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(in[i]+in[j]==m)
                {
                    x=i;y=j;
                }
            }

        }
        cout<<x+1<<" "<<y+1<<endl;
    }
}
void Interesting_drink_solution()
{
    int n,m;
    cin>>n;
    vector<int>in(n);
    for(int i=0;i<n;i++)
        cin>>in[i];
    sort(in.begin(),in.end());
    cin>>m;
    int x;
    for(int i=0;i<m;i++)
    {
        cin>>x;
        vector<int>::iterator it=upper_bound(in.begin(),in.end(),x);
        int index=it-in.begin();
        cout<<index<<endl;
    }
}

void Worms_solution()
{
    int n,m,x;
    cin>>n;
    vector<int>worms(n);
    cin>>x;
    worms[0]=x;
    for(int i=1;i<n;i++)
    {
        cin>>x;
        worms[i]=worms[i-1]+x;
    }
    cin>>m;
    while(m--)
    {
        cin>>x;
        vector<int>::iterator it=upper_bound(worms.begin(),worms.end(),x);
        int index=it-worms.begin();
        if(index==0)cout<<index+1<<endl;
        else if(x>worms[index-1]&&x<=worms[index]) cout<<index+1<<endl;
        else cout<<index<<endl;
    }
}
int main()
{
    Worms_solution();
    //Interesting_drink_solution();
    //ICE_cream_parlor_solutionn();
    return 0;
}
