#include <bits/stdc++.h>
using namespace std;

typedef struct tree_node
{
    int key;
    struct tree_node* left;
    struct tree_node* right;
    tree_node(int k)
    {
        key=k;
        left=NULL;
        right=NULL;
    }
    void insert_left(struct tree_node* l)
    {
        left=l;
    }
    void insert_right(struct tree_node* r)
    {
        right=r;
    }
}node;
void count_edges(struct tree_node*root,int&count)
{
    if(root==NULL) return;
    if(root->left!=NULL)
    {
        if(root->key>root->left->key)
            count++;
    }
    if(root->right!=NULL)
    {
        if(root->key>root->right->key)
            count++;
    }
    count_edges(root->left,count);
    count_edges(root->right,count);
}
void counting_defect_edges(struct tree_node* root)
{
    int count=0;
    count_edges(root,count);
    cout<<count;
}
int main()
{
    node* root=new node(5);
    node* n1=new node(4);
    node* n2=new node(11);
    root->insert_left(n1);
    root->insert_right(n2);
    node* n3=new node(14);
    node* n4=new node(7);
    n1->insert_left(n3);
    n1->insert_right(n4);
    node* n5=new node(14);
    node* n6=new node(18);
    n2->insert_left(n5);
    n2->insert_right(n6);
    node* n7=new node(11);
    n5->insert_left(n7);
    node* n8=new node(7);
    node* n9=new node(7);
    n4->insert_left(n8);
    n4->insert_right(n9);
    node* n10=new node(12);
    node* n11=new node(7);
    n6->insert_left(n10);
    n6->insert_right(n11);
    counting_defect_edges(root);
    return 0;
}
