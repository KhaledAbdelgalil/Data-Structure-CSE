#include <iostream>
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
    Tree_Node * in_order_successor_right()
	{
		Tree_Node * leftmostrightsubtree = right;
		while (leftmostrightsubtree!= NULL && leftmostrightsubtree->left != NULL)
		{
			leftmostrightsubtree = leftmostrightsubtree->left;
		}
		return leftmostrightsubtree;
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
    void remove(int value)
    {
        remove(root,value);
    }
    void remove(Tree_Node * &  root_node, int value)
	{
		Tree_Node * targetnode = root_node;
		Tree_Node * parent = NULL;

		bool left_child = false;
		while (targetnode != NULL) {
			int t = targetnode->value;
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
		if (targetnode->is_leaf())
		{
			//http://www.algolist.net/img/bst-remove-case-1.png
			if (parent == NULL) // root node is the found node
			{
				Tree_Node * temp = root_node;
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
			Tree_Node * leftmostrightsubtree = targetnode->in_order_successor_right();
			// swapped the elements
			targetnode->value = leftmostrightsubtree->value;
			remove(targetnode->right, targetnode->value);
		}
	}

Tree_Node* get_root()
	{
		return root;
	}

	void inorder_traversal(Tree_Node * root)
	{
		if (root == NULL)
			return;
		inorder_traversal(root->left);
		cout << root->value<< " " ;
		inorder_traversal(root->right);
	}

	void preorder_traversal(Tree_Node * root)
	{
		if (root == NULL)
			return;
		cout << root->value<< " ";
		preorder_traversal(root->left);
		preorder_traversal(root->right);
	}

	void postorder_traversal(Tree_Node * root)
	{
		if (root == NULL)
			return;
		postorder_traversal(root->left);
		postorder_traversal(root->right);
		cout << root->value << " ";

	}

};
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

void test_insert()
{
	BST test;
	initialize(test);
	test.inorder_traversal(test.get_root());
}
//					7
//			3				11
//		1		5		9		13
//    0	  2   4   6   8  10   12   14
void test_remove()
{
	BST test;
	initialize(test);
	for (size_t i = 0; i < 15; i++)
	{
		cout << "Removing " << test.get_root()->get_value() << endl;
		test.inorder_traversal(test.get_root());
		cout << endl;
		test.remove(test.get_root()->get_value());

	}
	cout << endl << endl;
	initialize(test);
	for (size_t i = 0; i < 15; i++)
	{
		cout << "Removing " << i << endl;
		test.inorder_traversal(test.get_root());
		cout << endl;
		test.remove(i);
	}
	cout << endl << endl;

	initialize(test);
	for (size_t i = 0; i < 15; i++)
	{
		cout << "Removing " << 14- i << endl;
		test.inorder_traversal(test.get_root());
		cout << endl;
		test.remove(14 - i);
	}
}

int main()
{

    test_insert();
    return 0;
}
