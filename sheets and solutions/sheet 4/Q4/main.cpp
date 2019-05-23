//recomended problem for maze:B. Infinite Maze::https://codeforces.com/problemset/problem/196/B

#include <bits/stdc++.h>
using namespace std;
#define v 100
char a[1510][1510];
int n,m;
pair<int,int>visited[1510][1510];
void dfs_maize(int x,int y)
{
    int i=((x%n)+n)%n;
    int j=((y%m)+m)%m;
    if(a[i][j]=='#') return;
    if(visited[i][j]==make_pair(x,y)) return;
    if(visited[i][j].first!=2000&&visited[i][j].second!=2000)
    {
        cout<<"YES";
        exit(0);
    }
    visited[i][j]=make_pair(x,y);
    dfs_maize(x-1,y);
    dfs_maize(x+1,y);
    dfs_maize(x,y-1);
    dfs_maize(x,y+1);
}
void Infinite_Maze_solution()
{
    cin>>n>>m;
    int x,y;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            visited[i][j]=make_pair(2000,2000);
            if(a[i][j]=='S')
            {
                x=i;
                y=j;
            }
        }
    }
    dfs_maize(x,y);
    cout<<"NO";
}



// Q4
bool Q4_is_there_a_way_out(vector<list<int> > & adjacency_list, int source, int target)
{
	stack<int> to_be_visited;
	vector<bool> visited(v,false);
	to_be_visited.push(source);
	visited[source] = true;
	while (!to_be_visited.empty())
	{
		int current_node = to_be_visited.top(); to_be_visited.pop();
		if (current_node == target)
		{
			return true;
		}
		for (list<int>::iterator itr = adjacency_list[current_node].begin();
			itr != adjacency_list[current_node].end(); itr++)
		{

			if (!visited[*itr])
			{
				to_be_visited.push(*itr);
				visited[*itr] = true;
			}
		}
	}
	return false;
}

int main()
{
    Infinite_Maze_solution();
    return 0;
}
