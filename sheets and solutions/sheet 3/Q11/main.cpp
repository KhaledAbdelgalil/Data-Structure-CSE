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
void keysbetween(Tree_node* root, int k1, int k2)
{
	if (root == NULL)
		return;
	if(root->value > k1)
		keysbetween(root->left, k1, k2);
	if (root->value >= k1 && root->value <= k2)
		cout << root->value << " " ;
	if (root->value < k2)
		keysbetween(root->right, k1, k2);

}
void Testing()
{
	BST bst;
	initialize(bst);
	keysbetween(bst.root, 5, 10);
}

int main()
{
    Testing();
    return 0;
}
