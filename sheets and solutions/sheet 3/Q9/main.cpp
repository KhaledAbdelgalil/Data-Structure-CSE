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
int sum_left_leaves(Tree_node* root,bool left=true)
{
    if(root==NULL) return 0;
    if(root->left==NULL&&root->right==NULL&&left) return root->value;
    return sum_left_leaves(root->left,true)+sum_left_leaves(root->right,false);
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
    cout<<sum_left_leaves(root)<<endl;
}
void Testing2()
{

    Tree_node* n8=new Tree_node(9);
    Tree_node* n4=new Tree_node(5);
    Tree_node* n5=new Tree_node(6);
    Tree_node* n6=new Tree_node(7);
    Tree_node* n7=new Tree_node(8,n8);
    Tree_node* n2=new Tree_node(3,n5,n6);
    Tree_node* n3=new Tree_node(4,NULL,n7);
    Tree_node* n1=new Tree_node(2,n3,n4);
    Tree_node* root=new Tree_node(1,n1,n2);
    cout<<sum_left_leaves(root)<<endl;
}
int main()
{
    Testing2();
    return 0;
}
