//problem:https://www.hackerrank.com/challenges/balanced-brackets/problem
//problem:https://codeforces.com/contest/5/problem/C
#include <iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
void Balanced_Brackets_solution()
{
    int t;
    cin>>t;
    string s;
    while(t--)
    {
    cin>>s;
    stack<char> stk;
    int flag=1;
    for(int i=0; i < s.size(); i++)
        {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
           {
                stk.push(s[i]);
            }
        else if(!stk.empty() &&
                    (s[i] == ')' && stk.top() == '(' ||
                     s[i] == '}' && stk.top() == '{' ||
                     s[i] == ']' && stk.top() == '['))
            {
                stk.pop();
            }
        else
                {flag=0; break;}
        }
        if(stk.empty()&&flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

int main()
{
    Balanced_Brackets_solution();
    return 0;
}
