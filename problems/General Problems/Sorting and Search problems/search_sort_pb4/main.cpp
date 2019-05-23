//problem:https://codeforces.com/problemset/problem/279/B
#include <bits/stdc++.h>

using namespace std;

void Books_solution()
{
    int books,freetime,sum,output=0;
    cin>>books>>freetime;
    int i=0,j=0;
    vector<int> books_arr(books);

    for(int i=0;i<books;i++)
        cin>>books_arr[i];
    sum=books_arr[0];
    while(j!=books)
    {
        if(sum<=freetime)
        {
          output=max(output,j-i+1);
          j++;
          sum+=books_arr[j];
        }
        else
        {
            sum-=books_arr[i];
            i++;
            if(i==j)
            {
            j++;
            sum+=books_arr[j];
            }
        }
    }
    cout<<output;
}


void Books_solution2()
{
    int n,free;
    int temp;
    cin>>n>>free;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        if(i==0)
            arr[i]=temp;
        else arr[i]=temp+arr[i-1];
    }
    int max_books=0;
    for(int i=0;i<n;i++)
    {
        int index;
        if(i==0)
         index=upper_bound(arr.begin(),arr.end(),free)-arr.begin();
        else
            index=upper_bound(arr.begin(),arr.end(),free+arr[i-1])-arr.begin();
            index-=i;
            max_books=max(index,max_books);
    }
    cout<<max_books;
}
int main()
{
    Books_solution2();
    return 0;
}
