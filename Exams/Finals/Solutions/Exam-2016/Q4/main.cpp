#include <iostream>
#include<list>
#include<queue>
using namespace std;
class node
{
public:
    string id;
    list<node*>children;
    node(){}
};
void give_id_helper(node* root)
{
    if(root==NULL) return;
    int i=1;
    for(list<node*>::iterator it=root->children.begin();it!=root->children.end();it++)
    {
        (*it)->id=root->id+"."+char(i+48);
        i++;
        give_id_helper(*it);
    }
}
void print(node* root)
{
    if(root==NULL) return;
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* f=q.front();
        cout<<f->id<<" ";
        q.pop();
        for(list<node*>::iterator it=f->children.begin();it!=f->children.end();it++)
        {
            q.push(*it);
        }
    }
}
class Tree
{
public:
    node* root;
    Tree()
    {
      root=NULL;
    }
    void giving_id()
    {
      if(root==NULL) return;
      root->id="1";
        give_id_helper(root);
    }
};


int main()
{
    Tree h;
    h.root=new node();
    node* n1=new node();
    node* n2=new node();
    node* n3=new node();
    node* n4=new node();
    node* n5=new node();
    node* n6=new node();
    node* n7=new node();
    n1->children.push_back(n4);
    n4->children.push_back(n6);
    n1->children.push_back(n5);
    n2->children.push_back(n7);
    h.root->children.push_back(n1);
    h.root->children.push_back(n2);
    h.root->children.push_back(n3);


    h.giving_id();
    print(h.root);
    return 0;
}
