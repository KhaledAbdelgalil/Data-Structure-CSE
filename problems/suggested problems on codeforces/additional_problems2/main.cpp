//problem::https://codeforces.com/contest/631/problem/A
//problem::https://codeforces.com/problemset/problem/525/A
//problem::https://codeforces.com/contest/318/problem/A
//problem::https://codeforces.com/contest/834/problem/A
//problem::https://codeforces.com/problemset/problem/919/A
//problem::https://codeforces.com/problemset/problem/4/C
//problem::https://codeforces.com/problemset/problem/955/B
//problem::https://codeforces.com/contest/670/problem/A
#include <bits/stdc++.h>
using namespace std;
void Interview_solution()
{
    int n,x,out1=0,out2=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        out1|=x;
    }
     for(int i=0;i<n;i++)
    {
        cin>>x;
        out2|=x;
    }
    cout<<out1+out2;
}

void Vitaliy_and_Pie_solution()
{
    string in;
    map<char,int>keys;
    int rooms;
    int res=0;

    cin>>rooms;
    cin>>in;

    for(int i=0;i<in.size();i++)
    {
        if(islower(in[i]))
        {
            in[i]=toupper(in[i]);
            keys[in[i]]++;
        }
        else
        {
            if(keys[in[i]]>0) keys[in[i]]--;
            else res++;
        }
    }
    cout<<res;
}

void Even_Odds_solution()
{
long long n,k;
    cin>>n>>k;
    if(n%2!=0&&k==(n/2)+1) cout<<n;


    else if(k>n/2)
        {
            if(n%2==0)
             k=k-n/2;
            else k=k-n/2-1;
             cout<<k*2;
        }
    else cout<<k*2-1;
}

void The_Useless_Toy_solution()
{
    char s,e;
    int n;
    cin>>s>>e>>n;
    n=n%4;
    if(n==2)
    {
        cout<<"undefined"<<endl;
    }
    else if(n==0) cout<<"undefined"<<endl;

    else if(n==1)
    {
        if((s=='<'&&e=='^')||(s=='^'&&e=='>')||(s=='>'&&e=='v')||(s=='v'&&e=='<')) cout<<"cw";
        else cout<<"ccw";
    }
    else if(n==3)
    {
        if((s=='<'&&e=='v')||(s=='^'&&e=='<')||(s=='>'&&e=='^')||(s=='v'&&e=='>')) cout<<"cw";
        else cout<<"ccw";
    }
    else cout<<"undefined";
}


void Supermarket_solution()
{
    int n;
    double m;
    double x,y;
    double minn=100000000000000;
    cin>>n>>m;
    while(n--)
    {
        cin>>x>>y;
       if(1.0*x/y<minn) minn=1.0*x/y;
    }
    cout.precision(10);
    cout<<minn*m;
}

void Registration_system()
{
    map<string,int>database;
    string temp;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>temp;
        if(database[temp]==0)
        {
            database[temp]++;
            cout<<"OK"<<endl;
        }
        else
        {
            cout<<temp<<database[temp]++<<endl;
        }
    }
}


void Not_simply_beatiful_strings()
{
    string in;
    map<char,int>ch;
    cin>>in;
    for(int i=0;i<in.size();i++)
    {
        ch[in[i]]++;
    }
    if(ch.size()==4) cout<<"YES";
    else if(ch.size()>4||ch.size()==1) cout<<"NO";
    else if(ch.size()==3)
    {
        int cnt=0;
        for(map<char,int>::iterator it=ch.begin();it!=ch.end();it++)
        {
            if(it->second>1) cnt++;
        }
        if(cnt>=1) cout<<"YES";
        else cout<<"NO";
    }
    else if(ch.size()==2)
    {
        int cnt=0;
        for(map<char,int>::iterator it=ch.begin();it!=ch.end();it++)
        {
            if(it->second>1) cnt++;
        }
        if(cnt==2) cout<<"YES";
        else cout<<"NO";
    }
}

void Holidays_solution()
{
    int n;
    cin>>n;
    if(n%7==0)
    cout<<2*(n/7)<<" "<<2*(n/7);
    else if(n%7==6)
    cout<<2*(n/7)+1<<" "<<2*(n+1)/7;
    else if(n%7==1)
    cout<<2*(n/7)<<" "<<2*(n/7)+1;
    else
    cout<<2*(n/7)<<" "<<2*(n/7)+2;
}
int main()
{
    Holidays_solution();
    //Not_simply_beatiful_strings();
   // Registration_system();
    //Supermarket_solution();
    //The_Useless_Toy_solution();
    //Even_Odds_solution();
    //Vitaliy_and_Pie_solution();
    //Interview_solution();
    return 0;
}
