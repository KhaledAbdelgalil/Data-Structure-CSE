#include <iostream>
#include<queue>
using namespace std;
class BST_node
{
public:
    string value;
    BST_node *left;
    BST_node *right;
    BST_node(string v)
    {
        value=v;
        left=NULL;
        right=NULL;
    }
    BST_node * in_order_successor_right()
	{
		BST_node * leftmostrightsubtree = right;
		while (leftmostrightsubtree!= NULL && leftmostrightsubtree->left != NULL)
		{
			leftmostrightsubtree = leftmostrightsubtree->left;
		}
		return leftmostrightsubtree;
	}

};
class BST_tree
{
public:
    BST_node *root;
    BST_tree()
    {
        root=NULL;
    }

    bool insert(string value)
    {
        if(root == NULL){
			root = new BST_node(value);
			return true;
		}
		BST_node * temp = root;
		while (temp!=NULL){
			string t = temp->value;
			if (value == t){
				return false; // can't insert
			}
			else if (value < t){
				if (temp->left == NULL){
					temp->left=new BST_node(value);
					return true;
				}
				else
					temp = temp->left;
			}
			else{
				if (temp->right == NULL){
					temp->right=new BST_node(value);
					return true;
				}
				else
					temp = temp->right;
			}
		}
    }
    void print()
    {
        if(root==NULL)
            return;

        queue< pair<BST_node*,int> >q;
        q.push({root,0});
        while(!q.empty())
        {
            pair<BST_node*,int>s=q.front();
            q.pop();
            BST_node* f=s.first;
            int level=s.second;
            if(f!=NULL) cout<<"level: "<<level<<" value: "<<f->value<<endl;;
            if(f->left!=NULL) q.push({f->left,level+1});
            if(f->right!=NULL) q.push({f->right,level+1});
            //cout<<"OK"<<endl;
        }
    }
    void remove(string value)
    {
        remove(root,value);
    }

    void remove(BST_node* root_node,string value)
	{
		BST_node * targetnode = root_node;
		BST_node * parent = NULL;

		bool left_child = false;
		while (targetnode != NULL) {
			string t = targetnode->value;
			if (value == t) {
				break;
			}
			else if (value < t) {
				parent = targetnode;
				left_child = true;
				targetnode = targetnode->left;
			}
			else {
				left_child = false;
				parent = targetnode;
				targetnode = targetnode->right;
			}
		}
		// now targetnode --> points to the to be deleted node
		if (targetnode->left==NULL&&targetnode->right==NULL)
		{
			//http://www.algolist.net/img/bst-remove-case-1.png
			if (parent == NULL) // root node is the found node
			{
				BST_node * temp = root_node;
				root_node = NULL;
				delete temp;
			}
			else if (left_child) {
				delete parent->left; parent->left = NULL;
			}
			else {
				delete parent->right; parent->right = NULL;
			}
		}
		else if (targetnode->left == NULL) {
			//http://www.algolist.net/img/bst-remove-case-2-2.png
			if (parent == NULL) { // root should be deleted and it has only a right child
				root_node = targetnode->right;
			}
			else if (left_child) //
				parent->left = targetnode->right;
			else
				parent->right = targetnode->right;
			delete targetnode;
		}
		else if (targetnode->right == NULL) {
			if (parent == NULL) { // root should be deleted and it has only a right child
				root_node = targetnode->left;
			}
			else if (left_child)
				parent->left = targetnode->left;
			else
				parent->right = targetnode->left;
			delete targetnode;
		}
		else {
			// get the leftmost of the right subtree
			BST_node * leftmostrightsubtree = targetnode->in_order_successor_right();
			// swapped the elements
			targetnode->value = leftmostrightsubtree->value;
			remove(targetnode->right, targetnode->value);
		}
	}




};
int main()
{
    BST_tree t;
    t.insert("cairo");
    t.insert("aswan");
    t.insert("alex");
    t.insert("tanta");
    t.insert("banha");
    t.insert("ismailia");
    t.insert("luxor");
    t.insert("suze");
    t.print();
    t.remove("aswan");
    t.remove("suze");
    t.print();
    return 0;
}
