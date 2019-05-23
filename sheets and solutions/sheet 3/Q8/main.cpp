#include <bits/stdc++.h>
using namespace std;

class Tree_node{
public:
    Tree_node* left;
    Tree_node* right;
    int value;
    Tree_node(int v,Tree_node* l=NULL,Tree_node* r=NULL)
    {
        value=v;
        left=l;
        right=r;
    }

};
void printing_path(list<int>&path)
{
    for(list<int>::iterator it=path.begin();it!=path.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void path(Tree_node* root,list<int>&pathh)
{
    if(root==NULL) return;
    pathh.push_back(root->value);

    if(root->left==NULL&&root->right==NULL)
    {
        printing_path(pathh);
        pathh.pop_back();
    }
    else
    {
        path(root->left,pathh);
        path(root->right,pathh);
        pathh.pop_back();
    }
}
void Testing()
{
    Tree_node* n1=new Tree_node(8);
    Tree_node* n2=new Tree_node(7);
    Tree_node* n3=new Tree_node(6,NULL,n1);
    Tree_node* n4=new Tree_node(3,NULL,n3);
    Tree_node* n5=new Tree_node(4);
    Tree_node* n6=new Tree_node(1,n4,n5);
    Tree_node* n7=new Tree_node(5,NULL,n2);
    Tree_node* n8=new Tree_node(2,n7);
    Tree_node* root=new Tree_node(0,n6,n8);
    list<int>pathh;
    path(root,pathh);
}
int main()
{
    Testing();
    return 0;
}
