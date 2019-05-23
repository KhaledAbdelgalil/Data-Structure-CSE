//pageRank of a given website depends on pageRank of other websites pointing to this website
//handle probablities in a matrix and sum of every col. will be 1
//initial vector is the initial pageRank assigened to pages
//problems with dangling nodes nodes with no outgoing edges also disconnected components
//use damping factor d d not follow links and leave website


//image found at project is for this example
#include <bits/stdc++.h>
using namespace std;

int nodes[]={0,1,2};
vector< vector< int > >adj_list(3);
map<int,int> no_of_times;
void initialize_edges()
{
    adj_list[0].push_back(1);
    adj_list[0].push_back(2);
    adj_list[1].push_back(0);
    adj_list[1].push_back(1);
    adj_list[2].push_back(0);
}
void Random_walks_browsing(int node,int timestamp,int limit)
{
    if(timestamp==limit)
        no_of_times[node]++;
    else
    {
        int next_node_index=rand()%adj_list[node].size();
        Random_walks_browsing(adj_list[node][next_node_index],timestamp+1,limit);
    }
}
int main()
{
    initialize_edges();
    int no_of_walk_browsing=10000;
    int max_walk_browse_length=10;
    for(int i=0;i<no_of_walk_browsing;i++)
    {
        int start_node=rand()%3;
        Random_walks_browsing(nodes[start_node],0,max_walk_browse_length);
    }
    float nodes_prob[3];
    for(int i=0;i<3;i++)
    {
        nodes_prob[i]=float(no_of_times[i])/float(no_of_walk_browsing);
        cout<<"Probability of ending at node ("<<i<<") is : "<<nodes_prob[i]<<endl;
    }

    return 0;
}
