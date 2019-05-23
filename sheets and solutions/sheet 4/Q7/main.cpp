#include <bits/stdc++.h>
using namespace std;
int n,m;
void Q7_shortest_flights_count(vector<list<int> > & adjacency_list, int src, int dst)
{
	vector<int> distance(n, -1);
	distance[src] = 0;
	vector<int> parent(n, -1);
	queue<int> being_visited;
	being_visited.push(src);
	bool found = false;
	while (!found && !being_visited.empty())
	{
		int current_node = being_visited.front(); being_visited.pop();
		if (current_node == dst)
		{
			found = true;
			break;
		}
		for (list<int>::iterator itr = adjacency_list[current_node].begin();
			itr != adjacency_list[current_node].end(); itr++)
		{
			int index = *itr;
			if (distance[index] == -1)
			{
				distance[index] = distance[current_node] + 1;
				parent[index] = current_node;
				being_visited.push(index);
			}
		}
	}

	if(distance[dst] == -1)
		cout << "not found"<< endl;
	else
	{
		cout << "distance = " << distance[dst] << endl;
		int temp = dst;
		stack<int> path;
		do
		{
			path.push(temp);
			temp = parent[temp];
		} while (parent[temp] != -1);
		path.push(src);
		while (path.size()!=1)
		{
			cout << path.top() << " -> ";
			path.pop();
		}
		cout<<path.top();
	}

}
int main()
{

    cin>>n>>m;
    vector< list<int> > adj_list(n);
    int x,y;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
    int src,dist;
    cin>>src>>dist;
    Q7_shortest_flights_count(adj_list,src,dist);
    return 0;
}
