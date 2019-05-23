#include <bits/stdc++.h>
using namespace std;
//dfs:depth first search if you see a node walk behind it (go deeper),bfs:walk to nearst level first better to use adjancy list
//dfs :recursive gives you option to make something before visiting node pre and after visiting post
//dfs:it will go deeper until not find exit if then backtrack if find exit go deeper and so on
//sequential using stack top of stack makes you always go in deeper
//better to mark when pushing into stack to be visited in order not to be taken two times;
//bfs:explore graph level by level take a step and see if it comes use queue to do it




// graph implementation
int v = 1000;
int e = 20000;
// adjacency matrix
vector<vector<int> > adj_mat(v, vector<int>(v));

// adjacency list
vector<list<int> > adj_list(v);


// edge list
vector<pair<int, int> > edge_list(e);


// cost |E| + |V|, space |V|
void dfs(vector<list<int> > & adjacency_list, int &source)
{
	stack<int> to_be_visited;
	to_be_visited.push(source);
	vector<bool> visited(adjacency_list.size(),0); // the same as vertices
	visited[source] = true;
	while (!to_be_visited.empty())
	{
		int current_node = to_be_visited.top(); to_be_visited.pop();

		for (list<int>::iterator itr = adjacency_list[current_node].begin();
			itr != adjacency_list[current_node].end(); itr++)
		{
			if (!visited[*itr])
			{
				visited[*itr] = true;
				to_be_visited.push(*itr);
			}
		}
	}
}

void dfs(vector<list<int> > & adjacency_list, vector<bool> & visited,	int source)
{
	visited[source] = true;
	// pre
	for (list<int>::iterator itr = adjacency_list[source].begin();
		itr != adjacency_list[source].end(); itr++)
	{
		if (!visited[*itr])
		{
			dfs(adjacency_list, visited,*itr);
		}
	}
	// post
}

void dfs(vector<list<int> > & adjacency_list,vector<bool> & visited,vector<int> &pre,
	vector<int> &post, int source, int &timer)
{
	visited[source] = true;
	// pre
	pre[source] = timer++;//all connected nodes pre post are in specified range see image:
	for (list<int>::iterator itr = adjacency_list[source].begin();
		itr != adjacency_list[source].end(); itr++)
	{
		if (!visited[*itr])
		{
			dfs(adjacency_list, visited,pre,post, *itr,timer);
		}
	}
	// post
	post[source] = timer++;
}

void bfs(vector<list<int> > & adjacency_list, int &source)
{
	queue<int> to_be_visited;
	to_be_visited.push(source);
	vector<int> visited(adjacency_list.size(),0); // the same as vertices
	visited[source] = true;
	while (!to_be_visited.empty())
	{
		int current_node = to_be_visited.front(); to_be_visited.pop();
		for (list<int>::iterator itr = adjacency_list[current_node].begin();
			itr != adjacency_list[current_node].end(); itr++)
		{
			if (!visited[*itr])
			{
				visited[*itr] = true;
				to_be_visited.push(*itr);
			}
		}
	}
	// post
	// here you can check for visited nodes
}

int main()
{
    return 0;
}
