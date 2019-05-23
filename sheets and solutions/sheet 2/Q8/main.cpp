#include <iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> Q8_solution_remove_dublicates(vector<int>&A)
{
    stack<int>s;
    s.push(A[0]);
    for(int i=1;i<A.size();i++)
    {
        if(s.top()!=A[i]) s.push(A[i]);
    }
    vector<int>result(s.size());
    for(int i=s.size()-1;i>=0;i--)
    {
        result[i]=s.top();
        s.pop();
    }
    return result;
}
int main()
{
    int arr[]={1,1,1,1,2,2,2,2,3,3,4,5,6,6,7,8};
    vector<int>A(arr,arr+16);
    vector<int>result=Q8_solution_remove_dublicates(A);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<" ";


    return 0;
}
