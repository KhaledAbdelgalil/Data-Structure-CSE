//problem:https://codeforces.com/contest/5/problem/C
//problem:https://www.hackerrank.com/challenges/maximum-element/problem
//problem:https://codeforces.com/contest/158/problem/C
#include <iostream>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;
void Longest_Regular_Bracket_Sequence_solution()
{
    string s;
    cin>>s;
    stack<int>stk;
    map<int,int>values;
    stk.push(-1);
    int result=0;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(') stk.push(i);
        else
        {
            stk.pop();
            if(!stk.empty())
                {
                    values[i-stk.top()]++;
                    result=max(result,i-stk.top());
                }
            else stk.push(i);
        }
    }
    if(result==0) cout<<0<<" "<<1<<endl;
    else cout<<result<<" "<<values[result]<<endl;
}
void Maximum_element_solution()
{
stack<int>elements;
    stack<int>current_max;
    int N;
    int Q;
    int e;
    cin>>N;
    while(N--)
    {
        cin>>Q;
        if(Q==1)
        {
            cin>>e;
            //cout<<e;
            if(elements.empty())
            {
                elements.push(e);
                current_max.push(e);
            }
            else{
                elements.push(e);
                current_max.push(max(e,current_max.top()));
            }
        }
        else if(Q==2)
        {
            elements.pop();
            current_max.pop();
        }
        else if(Q==3)
        {
            cout<<current_max.top()<<endl;
        }
    }
}

void Cd_and_pwd_commands_solution()
{
    int n;
    cin>>n;
    string c;
    stack<string>path;
    stack<string>print;
    map<string,string>parents;
    //cout<<parents["ss"]<<" asas"<<endl;
    while(n--)
    {
        cin>>c;
        if(c=="cd")
        {
            string q="";
            cin>>c;
            if(c=="..")
                path.pop();
            else
            {
                for(int i=0;i<c.size();i++)
                {
                    if(c[i]=='/'){if(i==0){while(!path.empty())path.pop();}
                    else
                    {
                    if(q=="..") path.pop();
                    else path.push(q);
                    q="";
                    }
                    }
                    else
                    {
                      q+=c[i];
                    }
                }
               if(q=="..") path.pop();
               else path.push(q);
            }
        }
        else
        {
            if(path.size()==0) cout<<'/'<<endl;
            else
            {
                cout<<'/';
                while(!path.empty())
                {
                    print.push(path.top());
                    path.pop();
                }
                while(!print.empty())
                {
                    cout<<print.top()<<'/';
                    path.push(print.top());
                    print.pop();
                }
                cout<<endl;
            }
        }

    }
}


int main()
{

    //Cd_and_pwd_commands_solution();
    //Longest_Regular_Bracket_Sequence_solution();
    return 0;
}
