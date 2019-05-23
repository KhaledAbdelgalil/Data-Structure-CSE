//problem:https:https://www.hackerrank.com/challenges/equal-stacks/problem
//problem:https://www.hackerrank.com/challenges/simple-text-editor/problem
//problem:https://www.hackerrank.com/challenges/game-of-two-stacks/problem
#include <iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
void Equal_stacks_solution()
{
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    vector<int>arr1(n1);
    vector<int>arr2(n2);
    vector<int>arr3(n3);
    int h1=0,h2=0,h3=0;
    for(int i=0;i<n1;i++)
    {
        cin>>arr1[i];
        h1+=arr1[i];
    }
    for(int i=0;i<n2;i++)
    {
        cin>>arr2[i];
        h2+=arr2[i];
    }
    for(int i=0;i<n3;i++)
    {
        cin>>arr3[i];
        h3+=arr3[i];
    }
    if(h1==h2&&h2==h3)
    {
        cout<<h1;
        return;
    }
    int r1=0,r2=0,r3=0;
    bool equal=false;
    while(!equal)
    {
        if(h1>=h2&&h1>=h3)
            {
                h1-=arr1[r1];
                r1++;
            }
        else if(h2>=h1&&h2>=h3)
            {
                h2-=arr2[r2];
                r2++;
            }
        else if(h3>=h2&&h3>=h1)
            {
                h3-=arr3[r3];
                r3++;
            }
    if(h1==h2&&h2==h3)
    {
        cout<<h1;
        return;
    }
    }
}

void Simple_Text_editor_solution()
{
    int n;
    cin>>n;
    int op;
    string result="";
    string r;
    stack<string>undo;

    while(n--)
    {
        cin>>op;
        if(op==1) {
            undo.push(result);
            cin>>r;
            result+=r;

        }
        else if(op==2){
            undo.push(result);
            cin>>op;
            while(op--)
            {
                result.erase(result.size()-1,1);
            }
        }
        else if(op==3)
        {
            cin>>op;
            cout<<result[op-1]<<endl;
        }
        else if(op==4)
        {
            result=undo.top();
            undo.pop();
        }
    }

}

void Game_of_two_stacks_solution1()
{
    int t,n,m,x;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>x;
        vector<int>s1(n);
        vector<int>s2(m);
        for(int i=0;i<n;i++)
            cin>>s1[i];
        for(int i=0;i<m;i++)
            cin>>s2[i];
        int r1=0,r2=0;
        int result=0;
        int sum=0;

        while(r1<n&&s1[r1]+sum<=x)
        {
            sum+=s1[r1++];
        }
        int answer=r1;
        while(r2<m&&r1>=0)
        {
            sum+=s2[r2++];
            while(sum>x&&r1>0)
            {
                sum-=s1[--r1];
            }
            if(sum<=x&&answer<r1+r2)
            {
             answer=r1+r2;
            }
        }

        cout<<answer<<endl;
    }
}

void Game_of_two_stacks_solution2()
{
long long t,n,m,x;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>x;
        vector<long long>s1(n);
        vector<long long>s2(m);
        vector<long long >sacc1(n+1);
        vector<long long>sacc2(m+1);
        sacc1[0]=sacc2[0]=0;
        for(int i=0;i<n;i++)
            {
                cin>>s1[i];
                 sacc1[i+1]=s1[i]+sacc1[i];
            }
        for(int i=0;i<m;i++)
           {
                cin>>s2[i];
                 sacc2[i+1]=s2[i]+sacc2[i];
           }
           int answer=0;
    for(int i=0;i<=n;i++)
    {
        if(sacc1[i]<=x)
        {
            answer = max(answer, i+(int)((upper_bound(sacc2.begin(), sacc2.end(), x-sacc1[i]))-sacc2.begin()-1));
        }

    }
     cout<<answer<<endl;
}

}
void Largest_Rectangle_solution1()//O(n2)
{
    int n;
    cin>>n;
    vector<int>h(n);
    for(int i=0;i<n;i++)
        cin>>h[i];
        int out=0;
    for(int i=0;i<n;i++)
    {
        int indexLeft=i;
        int indexRight=i;
        while(indexLeft>0&&h[indexLeft-1]>h[i]) indexLeft--;
        while(indexRight<n-1&&h[indexRight+1]>h[i]) indexRight++;
        out=max(out,(indexRight-indexLeft+1)*h[i]);
    }
    cout<<out;
}

void Largest_Rectangle_solution2()//o(n)
{
    int n;
    cin>>n;
    vector<int>h(n+1);
    for(int i=0;i<n;i++)
        cin>>h[i];
    h[n]=0;
    long long out=0;
    stack<int>s;
    int i=0;
    while(i < h.size())
    {
        if(s.empty() || h[i] > h[s.top()])
        {
            s.push(i);
            i++;
        }
        else
        {
            int t = s.top();
            s.pop();

            out = max(out, h[t] * (s.empty() ? i : i - s.top() - 1));
        }
    }
    cout<<out;
}
int main()
{

    Largest_Rectangle_solution2();
    //Game_of_two_stacks_solution1();
    //Simple_Text_editor_solution();
    //Equal_stacks_solution();
    return 0;
}
