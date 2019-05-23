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
void initialize(BST & test)
{
    //					7
//			3				11
//		1		5		9		13
//    0	  2   4   6   8  10   12   14
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
int max(Tree_Node* root)
{
    if(root->get_right()==NULL) return root->get_value();

    return max(root->get_right());
}
int min(Tree_Node* root)
{
    if(root->get_left()==NULL) return root->get_value();
    return min(root->get_left());
}
int count_leaves(Tree_Node* root)
{
    if(root==NULL) return 0;
    if(root->get_left()==NULL&&root->get_right()==NULL) return 1;
    return count_leaves(root->get_left())+count_leaves(root->get_right());
}
void test_Q4_Q5()
{
	BST test;
	initialize(test);
	cout<<"expected max is:"<<max(test.get_root())<<endl;
    cout<<"expected min is:"<<min(test.get_root())<<endl;
    cout<<"expected number of leaves is: "<<count_leaves(test.get_root());

}


int main()
{
    test_Q4_Q5();
    return 0;
}
