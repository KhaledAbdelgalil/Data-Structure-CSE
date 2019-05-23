#include <bits/stdc++.h>
using namespace std;
class Tree_Node{
private:
    Tree_Node *left;
    Tree_Node *right;
    int value;
public:
    Tree_Node(int v)
    {
        left=NULL;
        right=NULL;
        value=v;
    }
    bool is_leaf()
    {
        return (left==NULL)&&(right==NULL);
    }
	int get_value()
	{
	    return value;
	}
	Tree_Node* get_left()
    {
        return left;
    }
    Tree_Node* get_right()
    {
        return right;
    }

    friend class BST;
};
class BST{
private: Tree_Node* root;
public:
    BST(){
        root=NULL;
    }
    Tree_Node* get_root(){
        return root;
    }
    bool insert(int value)
    {
        if(root == NULL){
			root = new Tree_Node(value);
			return true;
		}
		Tree_Node * temp = root;
		while (temp!=NULL){
			int t = temp->value;
			if (value == t){
				return false; // can't insert
			}
			else if (value < t){
				if (temp->left == NULL){
					temp->left=new Tree_Node(value);
					return true;
				}
				else
					temp = temp->left;
			}
			else{
				if (temp->right == NULL){
					temp->right=new Tree_Node(value);
					return true;
				}
				else
					temp = temp->right;
			}
		}
    }
};
void sort_BST(Tree_Node* root,vector<int>&res)
{
    if(root==NULL) return;
    sort_BST(root->get_left(),res);
    res.push_back(root->get_value());
    sort_BST(root->get_right(),res);
}
void sort2_BST(Tree_Node* root,vector<int>&res)
{
    if(root==NULL) return;
    sort2_BST(root->get_right(),res);
    res.push_back(root->get_value());
    sort2_BST(root->get_left(
                            ),res);
}
void Testing_sorting()
{
    BST test;
    int arr[]={2,3,10,0,9,8,4,1,6,7,5};
    for(int i=0;i<11;i++) test.insert(arr[i]);
    vector<int>res;
    sort2_BST(test.get_root(),res);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
}
int main()
{
    Testing_sorting();
    return 0;
}
