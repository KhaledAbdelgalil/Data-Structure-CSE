//1st problem(Gridland Metro):https://www.hackerrank.com/challenges/gridland-metro/problem
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> >v[1003];
map<int,int>mp;
void Gridland_Metro_solution()
{
    int n, m, k, r, c1, c2, sz1, sz2;
    long long ans;
    cin>>n>>m>>k;

    for(int i=0; i<k; i++){
        cin>>r>>c1>>c2;
        if(mp[r] == 0)
            mp[r] = mp.size();
        r = mp[r];
        v[r].push_back( make_pair(c1,c2) );
    }
    sz1 = mp.size();
    for(int i=1; i<=sz1; i++)
        sort(v[i].begin(), v[i].end());
    ans = (long long)n*(long long)m;
    long long countt=0;
    for(int i=1; i<=sz1; i++)
    {
        sz2 = v[i].size();

        int current_x=v[i][0].first;
        int current_y=v[i][0].second;
        countt+=current_y-current_x+1;
         for(int j=1;j<sz2;j++)
         {
                if(current_y<v[i][j].first)
                {
                    current_x=v[i][j].first;
                    current_y=v[i][j].second;
                    countt+=current_y-current_x+1;
                }
                else if(current_y>=v[i][j].first)
                {
                    if(current_y>v[i][j].second) continue;
                    current_x=current_y+1;
                    current_y=v[i][j].second;
                    if(current_x<=current_y)
                    {
                        countt+=current_y-current_x+1;
                    }
                }
         }
    }

    ans -= countt;
    cout<<ans<<"\n";
}
int main()
{
    Gridland_Metro_solution();
    return 0;
}
