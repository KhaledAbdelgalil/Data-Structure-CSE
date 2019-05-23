//problem::https://codeforces.com/problemset/problem/948/A
//problem::https://codeforces.com/contest/699/problem/A
//problem::https://codeforces.com/problemset/problem/955/A
//problem::https://codeforces.com/problemset/problem/546/B
//problem::https://codeforces.com/problemset/problem/676/A
//problem::https://codeforces.com/problemset/problem/936/A
#include <bits/stdc++.h>
using namespace std;

void Protect_Sheep_Solution()
{
    int n,m;
    cin>>n>>m;
    char a[n][m];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    int flag=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='W')
            {
                int x[]={1,-1,0,0};
                int y[]={0,0,1,-1};
                for(int k=0;k<4;k++)
                {
                    int LR=x[k]+i;
                    int UD=y[k]+j;
                    if(LR>=0&&LR<n&&UD>=0&&UD<m)
                    {
                        if(a[LR][UD]=='S') {flag=0;break;}
                        else if(a[LR][UD]=='.') a[LR][UD]='D';
                    }
                }

            }
            if(!flag) break;
        }
        if(!flag) break;
    }
    if(flag){
        cout<<"YES"<<endl;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                cout<<a[i][j];
                cout<<endl;
            }
            return;
    }
    cout<<"NO";
}

void  Launch_of_Collider_Solution()
{
    int n;
    cin>>n;
    string dir;
    cin>>dir;
    int minn=INT_MAX;
    int x,y;
    cin>>x;
    for(int i=1;i<n;i++)
    {
        cin>>y;

        if(dir[i-1]=='R'&&dir[i]=='L')
        {
                //x+t=y-t
                //2t=y-x
                //t=(y-x)/2
                int t=(y-x)/2;
                minn=min(t,minn);
        }
        x=y;
    }
if(minn==INT_MAX) cout<<-1;
else cout<<minn;
}

void Feed_the_cat_Solution()
{
    int hh,mm;
    cin>>hh>>mm;
    int H,D,C,N;
    cin>>H>>D>>C>>N;
    double required=ceil(double(H)/N);
    if(hh>=20)
    {
        double cost=required*C*80.0/100;
        cout<<cost;
        return;
    }
    double cost1=required*double(C);
    double time=0;
    if(mm==0)
    {
        time+=(20-hh)*60;
    }
    else {
        hh++;
        time+=(20-hh)*60+60-mm;
    }
    H+=D*(time);
    required=ceil(double(H)/N);
    double cost2=required*double(C)*80.0/100;
        cout<<min(cost1,cost2);
}


void Soldier_and_Badges_Solution()
{
  int n;
  cin>>n;
  set<int>s;
  int re=0;
  int a;
  for(int i=0;i<n;i++)
  {
        cin>>a;
        while(s.count(a))
        {
            a++;
            re++;
        }
        s.insert(a);
  }
  cout<<re;
}


void Nicholas_and_Permutation()
{
    int n;
    cin>>n;
    int index1,index2;
    int minn=INT_MAX,maxx=INT_MIN;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x<minn)
        {
            index1=i;
            minn=x;
        }
        if(x>maxx)
        {
            index2=i;
            maxx=x;
        }
    }
    if(index1<index2)
    {
        cout<<max(index2,n-1-index1);
    }
    else
        {
            cout<<max(index1,n-1-index2);
        }
}

void Save_Energy_Solution()
{
   long long k, d, t;
    cin>>k>>d>>t;

    t *= 2;

    d = (k + d - 1) / d * d;//if comes every second so it is always run

    long long time = 2 * k + (d - k);
    long long timeR = t % time;
    cout.precision(20);

    cout << d * (t / time) + (timeR > 2 * k ? (timeR - 2 * k) + k + 0.0 : timeR / 2.0) << endl;


}
int main()
{
    //Protect_Sheep_Solution();
    //Launch_of_Collider_Solution();
    //Feed_the_cat_Solution();
    //Soldier_and_Badges_Solution();
    //Nicholas_and_Permutation();
    Save_Energy_Solution();
    return 0;
}
