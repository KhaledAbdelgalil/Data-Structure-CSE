#include <bits/stdc++.h>
using namespace std;
//XML:don't close a parent tag untill all its children are closed
class XMLTree_node{
public:
    string tagname;
    string tagvalue;
    list<XMLTree_node*>children;

    XMLTree_node(string name, string value) :tagname(name), tagvalue(value){}

	void insert(XMLTree_node * node)
	{
		children.push_back(node);
	}
};
void XMLTree_to_text_simple(XMLTree_node * root)
{
	// openning bracket
	cout << "<" << root->tagname << "> " << root->tagvalue << " ";
	for (list<XMLTree_node*>::iterator itr = root->children.begin(); itr != root->children.end(); itr++)
	{
		XMLTree_to_text_simple(*itr);
	}
	// closing bracket
	cout << "</" << root->tagname << "> " << endl;
}
void XMLTree_to_text(XMLTree_node * root,int depth=0)
{

    for(int i=0;i<depth;i++) cout<<"\t";
    cout<< "<" << root->tagname << "> " << root->tagvalue << " ";
    if(root->children.size()>0)
		cout<< endl;
	for (list<XMLTree_node*>::iterator itr = root->children.begin(); itr != root->children.end(); itr++)
	{
		XMLTree_to_text(*itr,depth+1);
	}
	// closing bracket//will not find children so close
     if(root->children.size()>0)
		for (int i = 0; i < depth; i++)
		{
			cout << "\t";
		}
	cout << "</" << root->tagname << "> " << endl;
}
void test_xml_tree_node()
{
	XMLTree_node * root = new XMLTree_node("Book", "book11");
	XMLTree_node * child1_1 = new XMLTree_node("Author", "Adam");
	XMLTree_node * child1_2 = new XMLTree_node("Title", "Data Analysis");
	XMLTree_node * child2_1 = new XMLTree_node("Unit", "Data Cleaning");
	XMLTree_node * child2_2 = new XMLTree_node("Unit", "Data Gathering");
	XMLTree_node * child2_3 = new XMLTree_node("Unit", "Pattern Mining");

	root->insert(child1_1);
	root->insert(child1_2);
	child1_2->insert(child2_1);
	child1_2->insert(child2_2);
	child1_2->insert(child2_3);
    XMLTree_to_text(root);
	cout << endl;
	XMLTree_to_text_simple(root);
}
int main()
{
    test_xml_tree_node();
    return 0;
}
