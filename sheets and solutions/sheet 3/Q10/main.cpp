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
bool identical(Tree_node* root1,Tree_node* root2)
{
    if(root1==NULL&&root2==NULL) return true;
    if(root1==NULL||root2==NULL) return false;
    if(root1->value==root2->value) return identical(root1->left,root2->left)&&identical(root1->right,root2->right);
    else return false;
}
Tree_node* initialzation1()
{
    Tree_node* n1=new Tree_node(8,NULL);
    Tree_node* n2=new Tree_node(7);
    Tree_node* n3=new Tree_node(6,NULL,n1);
    Tree_node* n4=new Tree_node(3,NULL,n3);
    Tree_node* n5=new Tree_node(4);
    Tree_node* n6=new Tree_node(1,n4,n5);
    Tree_node* n7=new Tree_node(5,NULL,n2);
    Tree_node* n8=new Tree_node(2,n7);
    Tree_node* root=new Tree_node(0,n6,n8);
    return root;
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
    cout<<identical(root,initialzation1())<<endl;
}

int main()
{
    Testing();
    return 0;
}
