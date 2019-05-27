#include<iostream>
using namespace std;


class Tree_Node{
public:
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


Tree_Node* get_root()
	{
		return root;
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

void postorder_traversal(Tree_Node * root)
	{
		if (root == NULL)
			return;
		postorder_traversal(root->left);
		postorder_traversal(root->right);
		cout << root->value << " ";

	}

//					7
//			3				11
//		1		5		9		13
//    0	  2   4   6   8  10   12   14



class node
{
public:
    int value;
    node* next;
    node(int v)
    {
        value=v;
        next=NULL;
    }
};
class list
{
public:
    node* head;
    list()
    {
        head=NULL;
    }
    void push_front(int x)//O(1)
        {
            node* temp=new node(x);
            temp->next=head;
            head=temp;
            //must dynamic allocated to be created in heap so pointer that points to node will be deleted it's local but node itself will not
        }
    void push_back(int x)//O(n)
        {
            if(head==NULL){
                head=new node(x);
            }
            else
            {
                node* traverse_ptr=head;
                while(traverse_ptr->next!=NULL)
                {
                    traverse_ptr=traverse_ptr->next;
                }
                traverse_ptr->next=new node(x);
            }
        }

};
bool isHeap(int arr[],int n)
{
    for(int i=0;i<=(n-2)/2;i++)
    {
        if(arr[i*2+1]>arr[i]) return false;
        if(2*i+2<n&&arr[2*i+2]>arr[i]) return false;
    }
    return true;
}
int GetSum(node* head)
{
    int sum=0;
    if(head==NULL) return 0;
    node* temp=head;
    while(temp!=NULL)
    {
        sum+=temp->value;
        temp=temp->next;
    }
    return sum;
}

void printAll(node*root)
{
    if(root==NULL)return;
    printAll(root->next);
    cout<<root->value<<" ";
}
void Q4_a()
{
    int arr1[]={10,15,8,20,14,17,12,9,13};
    cout<<"Q4-a"<<endl;
    isHeap(arr1,9)?cout<<"is heap":cout<<"not a heap";
    cout<<endl;
}
void Q4_b()
{
    list t;
    t.push_front(1);
    t.push_front(2);
    t.push_front(3);
    t.push_front(4);
    t.push_front(5);
    cout<<GetSum(t.head);
}
void Q4_c()
{
    list t;
    t.push_back(1);
    t.push_back(2);
    t.push_back(3);
    t.push_back(4);
    t.push_back(5);
    printAll(t.head);
}

void Q4_d()
{
    BST test;
	initialize(test);
	postorder_traversal(test.get_root());
}
int main()
{
    //Q4_a();
    //Q4_b();
    //Q4_c();
    Q4_d();
    return 0;
}
