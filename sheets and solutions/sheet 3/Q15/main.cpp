#include <bits/stdc++.h>
using namespace std;
vector< pair< pair<string,string>,int > > database;
class Tree_node{
public:
    Tree_node* left;
    Tree_node* right;
    int index;

    string surname;
    Tree_node(int v,string s,Tree_node* l=NULL,Tree_node* r=NULL)
    {
        index=v;
        left=l;
        right=r;

        surname=s;
    }
};
class BST{
public: Tree_node* root;
BST()
	{
		root = NULL;
	}

	bool insert(int index,string surname)
	{
		if (root == NULL){
			root = new Tree_node(index,surname);
			return true;
		}
		Tree_node * temp = root;
		while (temp!=NULL){
			string t = temp->surname;
			if ( t==surname ){
				return false; // can't insert
			}
			else if (surname < t){
				if (temp->left == NULL){
					temp->left=new Tree_node(index,surname);
					return true;
				}
				else
					temp = temp->left;
			}
			else{
				if (temp->right == NULL){
					temp->right=new Tree_node(index,surname);
					return true;
				}
				else
					temp = temp->right;
			}
		}
	}


};

void creating_array()
{
    database.push_back(make_pair(make_pair("Ahmed","Saed"),98));
    database.push_back(make_pair(make_pair("Ramy","Salem"),110));
    database.push_back(make_pair(make_pair("Hend","Amr"),120));
    database.push_back(make_pair(make_pair("Merna","Yahya"),122));
    database.push_back(make_pair(make_pair("Ali","Saleh"),150));
    database.push_back(make_pair(make_pair("Mona","Kamel"),154));
    database.push_back(make_pair(make_pair("Mariam","Hasan"),155));
    database.push_back(make_pair(make_pair("Nour","Safwat"),160));
    database.push_back(make_pair(make_pair("Alaa","Baher"),162));
    database.push_back(make_pair(make_pair("Yousef","Ahmed"),165));
}
void creating_Tree(BST &bst)
{
    for(int i=0;i<10;i++)
    {
        bst.insert(i,database[i].first.second);
    }
}
int find_index(Tree_node* root,string surname)
{
    if(root==NULL) return -1;
    if(surname==root->surname) return root->index;
    if(surname<root->surname) return find_index(root->left,surname);
    return find_index(root->right,surname);
}
void inorder_traverse(Tree_node* root)
{
    if(root==NULL) return;
    inorder_traverse(root->left);
    cout<<root->surname<<" ";
    inorder_traverse(root->right);
}
int main()
{
    BST bst;
    creating_array();
    creating_Tree(bst);
    //inorder_traverse(bst.root);
    int index=find_index(bst.root,"Kamel");
    cout<<index<<database[index].first.first<<" "<<database[index].first.second<<" "<<database[index].second;
    return 0;
}
