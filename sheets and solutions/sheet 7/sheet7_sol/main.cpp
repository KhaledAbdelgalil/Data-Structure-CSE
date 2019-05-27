#include <iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
#define INF 10000000
int n=7,e=12;
vector<list <pair <int,int> > >adj_list(n);

void print_MST(int random)
{
    int n=adj_list.size();
    vector<bool>vis(n,0);
    vis[random]=1;//start at random element
    vector< pair< pair<int,int>,int > >print;
    priority_queue<pair< pair<int,int>,int >,vector < pair< pair<int,int>,int > >,greater<pair< pair<int,int>,int > > >q ;
    for(list< pair <int,int> >::iterator it=adj_list[random].begin();it!=adj_list[random].end();it++)
    {
        pair<int,int>s=*it;
        q.push({{s.second,s.first},random});
    }
    long long cost=0;
    while(!q.empty())
    {
        int w=q.top().first.first;
        int node=q.top().first.second;
        int parent=q.top().second;
        q.pop();
        if(vis[node]) continue;
        vis[node]=true;
        cost+=w;
        print.push_back({{parent,node},w});
        for(list< pair <int,int> >::iterator it=adj_list[node].begin();it!=adj_list[node].end();it++)
        {
            pair<int,int>s=*it;
            q.push({{s.second,s.first},node});
        }
    }
    cout<<"cost of spanning tree is : "<<cost<<endl;
    cout<<"edges:"<<endl;
    for(int i=0;i<print.size();i++)
    {
        cout<<char(65+print[i].first.first)<<" "<<char(65+print[i].first.second)<<" "<<print[i].second<<endl;
    }
}

void dijsktra(int source,int target)
{
   //distance - current node-parent node
   priority_queue< pair <int , pair <int , int> > ,
    vector< pair< int,pair<int ,int> > >,
    greater< pair < int,pair < int,int > > > > nodes;//distance-node-parent
    vector<int>d(n,INF);
    vector<int>p(n,-1);
    nodes.push({0,{source,source}});
    while(!nodes.empty())
    {
        pair <int , pair <int , int> > q=nodes.top();
        nodes.pop();
        int distance =q.first;
        int current_node=q.second.first;
        int parent_node=q.second.second;
        if(d[current_node]!=INF) continue;
        d[current_node]=distance;
        p[current_node]=parent_node;
        for(list< pair< int,int> >::iterator it=adj_list[current_node].begin();it!=adj_list[current_node].end();it++)
        {
            int next_node=(*it).first;
            int weight=(*it).second;
            if(d[next_node]!=INF)continue;
            nodes.push({distance+weight,{next_node,current_node}});
        }
    }
    cout<<"distance from: "<<char(source+65)<<" till "<<char(target+65)<<" is: "<<d[target]<<endl;
    vector<int>print;
    print.push_back(target);
    while(p[target]!=target)
    {
        print.push_back(p[target]);
        target=p[target];
    }
    cout<<"path is : ";
    for(int i=print.size()-1;i>=0;i--)
        cout<<char(print[i]+65)<<" ";
}
// A recursive function to print all paths from 'u' to 'd'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]
void printAllPathsUtil(int u, int d, bool visited[],
                            int path[], int &path_index)
{
    // Mark the current node and store it in path[]
    visited[u] = true;
    path[path_index] = u;
    path_index++;

    // If current vertex is same as destination, then print
    // current path[]
    if (u == d)
    {
        for (int i = 0; i<path_index; i++)
            cout << char(path[i]+65 )<< " ";
        cout << endl;

    }
    else // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current vertex
        list< pair< int,int > >::iterator i;
        for (i = adj_list[u].begin(); i != adj_list[u].end(); ++i)
            {
                pair< int,int > el=*i;
                if (!visited[el.first])
                printAllPathsUtil(el.first, d, visited, path, path_index);
            }
    }

    // Remove current vertex from path[] and mark it as unvisited
    path_index--;
    visited[u] = false;
}
void printAllPaths(int s, int d)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[n];

    // Create an array to store paths
    int *path = new int[n];
    int path_index = 0; // Initialize path[] as empty

    // Initialize all vertices as not visited
    for (int i = 0; i < n; i++)
        visited[i] = false;

    // Call the recursive helper function to print all paths
    printAllPathsUtil(s, d, visited, path, path_index);
}
//indepent

void printIndependentPathUtil(int u, int d, bool visited[],
                            int path[], int &path_index,bool visted2[])
{
    // Mark the current node and store it in path[]
    visited[u] = true;
    path[path_index] = u;
    path_index++;

    // If current vertex is same as destination, then print
    // current path[]
    if (u == d)
    {
        int flag=1;
        for(int i=1;i<path_index-1;i++)
        {

            if(visted2[path[i]]==1) {flag=0;break;}
        }
        if(flag)
        {
            for (int i = 0; i<path_index; i++)
                {
                    cout << char(path[i]+65 )<< " ";
                    if(i!=0&&i!=path_index-1)
                    {
                        visted2[path[i]]=1;
                    }
                }
            cout << endl;
        }


    }
    else // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current vertex
        list< pair< int,int > >::iterator i;
        for (i = adj_list[u].begin(); i != adj_list[u].end(); ++i)
            {
                pair< int,int > el=*i;
                if (!visited[el.first])
                printIndependentPathUtil(el.first, d, visited, path, path_index,visted2);
            }
    }

    // Remove current vertex from path[] and mark it as unvisited
    path_index--;
    visited[u] = false;
}
void printIndependentPaths(int s, int d)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[n];

    // Create an array to store paths
    int *path = new int[n];
    int path_index = 0; // Initialize path[] as empty
   bool *visited2 = new bool[n];
    // Initialize all vertices as not visited
    for (int i = 0; i < n; i++)
        {
            visited[i] = false;
            visited2[i]=0;
        }

    // Call the recursive helper function to print all paths
    printIndependentPathUtil(s, d, visited, path, path_index,visited2);
}


void initialize()
{
    adj_list[int('A'-'A')].push_back({int('B'-'A'),1});
    adj_list[int('A'-'A')].push_back({int('F'-'A'),6});
    adj_list[int('A'-'A')].push_back({int('G'-'A'),6});

    ////////////////////////////
    adj_list[int('B'-'A')].push_back({int('A'-'A'),1});
    adj_list[int('B'-'A')].push_back({int('F'-'A'),8});
    adj_list[int('B'-'A')].push_back({int('E'-'A'),3});
    adj_list[int('B'-'A')].push_back({int('C'-'A'),4});
    ///////////////////////////
    adj_list[int('C'-'A')].push_back({int('B'-'A'),4});
    adj_list[int('C'-'A')].push_back({int('E'-'A'),3});
    adj_list[int('C'-'A')].push_back({int('D'-'A'),5});
    //////////////////////////
    adj_list[int('D'-'A')].push_back({int('G'-'A'),7});
    adj_list[int('D'-'A')].push_back({int('F'-'A'),5});
    adj_list[int('D'-'A')].push_back({int('E'-'A'),4});
    adj_list[int('D'-'A')].push_back({int('C'-'A'),5});
    /////////////////////////
    adj_list[int('E'-'A')].push_back({int('B'-'A'),3});
    adj_list[int('E'-'A')].push_back({int('D'-'A'),4});
    adj_list[int('E'-'A')].push_back({int('C'-'A'),3});
    ////////////////////////
    adj_list[int('F'-'A')].push_back({int('A'-'A'),6});
    adj_list[int('F'-'A')].push_back({int('B'-'A'),8});
    adj_list[int('F'-'A')].push_back({int('D'-'A'),5});
    adj_list[int('F'-'A')].push_back({int('G'-'A'),1});
    ////////////////////////
    adj_list[int('G'-'A')].push_back({int('F'-'A'),1});
    adj_list[int('G'-'A')].push_back({int('A'-'A'),6});
    adj_list[int('G'-'A')].push_back({int('D'-'A'),7});
}




int main()
{
    initialize();
    cout<<"solution of Part1 is drawing memory representation"<<endl;
    cout<<"//////////////////////////////"<<endl<<endl;
    cout<<"solution of Part2 is :"<<endl;
    dijsktra(int('D'-'A'),int('A'-'A'));
    cout<<endl<<"//////////////////////////////"<<endl<<endl;
    cout<<"solution of Part3 is :"<<endl;
    printAllPaths(int('C'-'A'),int('F'-'A'));
    bool arr[n]={0};
    int paths[n]={0};
    int index=0;
    cout<<"solution of Part4 is :"<<endl;
        printIndependentPaths(int('C'-'A'),int('F'-'A'));
    cout<<endl<<"//////////////////////////////"<<endl<<endl;

    cout<<"solution of Part7&&8 is :"<<endl;
    print_MST(int('A'-'A'));

    return 0;
}
