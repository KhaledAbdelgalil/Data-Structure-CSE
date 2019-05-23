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
class BST{
public: Tree_node* root;
BST()
	{
		root = NULL;
	}

	bool insert(int value)
	{
		if (root == NULL){
			root = new Tree_node(value);
			return true;
		}
		Tree_node * temp = root;
		while (temp!=NULL){
			int t = temp->value;
			if (value == t){
				return false; // can't insert
			}
			else if (value < t){
				if (temp->left == NULL){
					temp->left=new Tree_node(value);
					return true;
				}
				else
					temp = temp->left;
			}
			else{
				if (temp->right == NULL){
					temp->right=new Tree_node(value);
					return true;
				}
				else
					temp = temp->right;
			}
		}
	}

};

//                 7
//			3				11
//		1		5		9		13
//    0	  2   4   6   8  10   12   14
void initialize(BST & test)
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
	test.insert(7);
	test.insert(3);
	test.insert(5);
	test.insert(1);
	test.insert(0);
	test.insert(2);
	test.insert(4);
	test.insert(6);

	test.insert(11);
	test.insert(9);
	test.insert(8);
	test.insert(10);
	test.insert(13);
	test.insert(12);
	test.insert(14);
}


bool is_complete(Tree_node* root)
{
    if(root==NULL||(root->left==NULL&&root->right==NULL))
        return true;
    queue<Tree_node*>q;
    q.push(root);
    bool flag_start_to_check_leaves=0;
    while(!q.empty())
    {
        if(!flag_start_to_check_leaves)
        {
            Tree_node* temp=q.front();
            if(temp->left==NULL&&temp->right!=NULL) return false;
            else if((temp->left==NULL&&temp->right==NULL)||(temp->left!=NULL&&temp->right==NULL))
            {
                if(temp->left!=NULL) q.push(temp->left);
                flag_start_to_check_leaves=true;
            }
            else
            {
                q.push(temp->left);
                q.push(temp->right);
            }
            q.pop();
        }
        else
        {
            Tree_node* temp=q.front();
            q.pop();
            if(!(temp->left==NULL&&temp->right==NULL)) return false;
        }
    }
    return true;
}
void Testing()
{
	// not exhaustive testing
	BST bst;
	initialize(bst);
	cout << is_complete(bst.root) << " << should be 1" << endl;
	bst.insert(-1);
	cout<< is_complete(bst.root) << " << should be 1" << endl;
	bst.insert(15);
	cout << is_complete(bst.root) << " << should be 0" << endl;
}


int main()
{
    Testing();
    return 0;
}
