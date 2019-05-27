#include <iostream>

using namespace std;
class BST_node{
public:
    int value;
    BST_node* left;
    BST_node* right;
    BST_node(int v)
    {
        value=v;
        left=NULL;
        right=NULL;
    }
};

int rec(BST_node* root)
{
    if(root==NULL) return 0;

    return 1+rec(root->left)+rec(root->right);
}
int main()
{
    //cout << "Hello world!" << endl;
    BST_node* root=new BST_node(5);
    BST_node* n1=new BST_node(4);
    BST_node* n2=new BST_node(10);
    BST_node* n3=new BST_node(7);
    BST_node* n4=new BST_node(9);
    root->left=n1;
    root->right=n2;
    n2->left=n3;
    n2->right=n4;
    cout<<rec(root);

    return 0;
}
