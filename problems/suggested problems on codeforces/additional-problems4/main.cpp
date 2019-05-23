//problem::https://codeforces.com/problemset/problem/448/A
//problem::https://codeforces.com/contest/365/problem/A
//problem::https://codeforces.com/contest/157/problem/A
//problem::https://codeforces.com/problemset/problem/255/A
#include <bits/stdc++.h>
using namespace std;
void Rewards_solution()
{
int x,y,z;
    cin>>x>>y>>z;
    int cups=x+y+z;
    cin>>x>>y>>z;
    int medals=x+y+z;
    cin>>x;
    while(x--)
    {
        if(cups==0&&medals==0) break;
        if(cups>0)
        {
            if(cups>5) cups-=5;
            else cups=0;
        }
        else
        {
            if(medals>10) medals-=10;
            else medals=0;
        }
    }
    if(cups==0&&medals==0) cout<<"YES";
    else cout<<"NO";
}

void Good_Number_solution()
{
    int n,k;
    cin>>n>>k;
    int counter=0;
    string x;
    int out=0;
    while(n--)
    {
        cin>>x;
        vector<bool>vis(10,0);
        int flag=1;
        counter=0;
        for(int i=0;i<x.size();i++)
        {
            switch(x[i])
            {
                case '0':if(!vis[0])counter++;
                            vis[0]=1;break;
                case '1': if(!vis[1]&&k>=1) counter++;

                            vis[1]=1;break;
                case '2':if(!vis[2]&&k>=2) counter++;

                        vis[2]=1;break;
                case '3':if(!vis[3]&&k>=3) counter++;

                        vis[3]=1;break;
                case '4':if(!vis[4]&&k>=4) counter++;

                        vis[4]=1;break;
                case '5':if(!vis[5]&&k>=5) counter++;

                        vis[5]=1;break;
                case '6':if(!vis[6]&&k>=6) counter++;

                        vis[6]=1;break;
                case '7':if(!vis[7]&&k>=7) counter++;

                        vis[7]=1;break;
                case '8':if(!vis[8]&&k>=8) counter++;

                        vis[8]=1;break;
                case '9':if(!vis[9]&&k>=9) counter++;

                        vis[9]=1;break;
            }

        }
        if(counter==k+1) out++;
    }
    cout<<out;
}

void  Game_Outcome_solution()
{
    int n;
    cin>>n;
    int arr[n][n];
    vector<int>rows(n,0);
    vector<int>cols(n,0);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
            rows[i]+=arr[i][j];
            cols[j]+=arr[i][j];
        }
        int counter=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
        {
            if(cols[j]>rows[i])counter++;
        }
        cout<<counter;
}

void Greg_Workout_solution()
{
    int n;
    cin>>n;
    int c=0,b=0,bb=0;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(i%3==0) c+=x;
        else if(i%3==1)b+=x;
        else bb+=x;
    }
    if(c>b&&c>bb) cout<<"chest";
    else if(b>c&&b>bb) cout<<"biceps";
    else cout<<"back";
}
int main()
{
    //Rewards_solution();
    //Good_Number_solution();
    //Game_Outcome_solution();
    Greg_Workout_solution();
    return 0;
}
