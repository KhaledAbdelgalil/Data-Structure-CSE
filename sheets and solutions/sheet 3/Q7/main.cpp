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
//passing parameter information from parent
void Printing_nodes_without_siblings(Tree_node* root,bool haveSiblings)
{
    if(root==NULL) return;
    if(root->left!=NULL&&root->right!=NULL)
    {
        Printing_nodes_without_siblings(root->left,true);
        if(!haveSiblings) cout<<root->value<<" ";
        Printing_nodes_without_siblings(root->right,true);
    }
    else
    {
        Printing_nodes_without_siblings(root->left,false);
        if(!haveSiblings) cout<<root->value<<" ";
        Printing_nodes_without_siblings(root->right,false);
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
    Printing_nodes_without_siblings(root,true);
}
int main()
{
    Testing();
    return 0;
}
