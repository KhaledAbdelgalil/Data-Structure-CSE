//problem:https://codeforces.com/problemset/problem/519/B

#include <bits/stdc++.h>
using namespace std;

void A_and_B_and_Compilation_Errors_solution()
{
    int n;
    cin>>n;
    vector<int>in(n);
    vector<int>in1(n-1);
    vector<int>in2(n-2);
    for(int i=0;i<n;i++)
        cin>>in[i];
    for(int i=0;i<n-1;i++)
        cin>>in1[i];
    for(int i=0;i<n-2;i++)
        cin>>in2[i];
    sort(in.begin(),in.end());
    sort(in1.begin(),in1.end());
    sort(in2.begin(),in2.end());
    int x=-1,y=-1;
    for(int i=0;i<n-1;i++)
    {
        if(in1[i]!=in[i]){
            x=in[i];
            break;
        }
    }
    if(x==-1) x=in[n-1];
    for(int i=0;i<n-2;i++)
    {
        if(in2[i]!=in1[i]){
            y=in1[i];
            break;
        }
    }
    if(y==-1) y=in1[n-2];
    cout<<x<<endl<<y;
}


void  Wizards_Duel_solution()
{
    double l,x,y;
    cin>>l>>x>>y;
    if(x==y) {cout<<l/2;return;}
    double answer;
    //d1/x=d2/y i.e d1*y=(l-d1)*x i.e d1(y+x)=l*x i.e d1=l*x/(x+y)
    double d1=l*x/(x+y);
    double d2=l-d1;
    double t1=d1/x;
    double t2=d2/y;
    if(t1<t2){
        double difference=t2-t1;
        double new_dist=difference*x;
        double new_l=l-new_dist;
        d1=new_l*x/(x+y);
        cout<<new_dist+d1<<endl;
    }
    else {
        double difference=t1-t2;
        double new_dist=difference*y;
        double new_l=l-new_dist;
        d1=new_l*x/(x+y);
        cout<<d1<<endl;
    }
}
int main()
{
    //A_and_B_and_Compilation_Errors_solution();
    Wizards_Duel_solution();
    return 0;
}
