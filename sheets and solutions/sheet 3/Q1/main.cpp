#include <bits/stdc++.h>
using namespace std;

class Tree_expression_node
{
public:
    char value;
    Tree_expression_node* left;
    Tree_expression_node* right;

    Tree_expression_node(char v,Tree_expression_node* l=NULL,Tree_expression_node* r=NULL)
    {
        value=v;
        left=l;
        right=r;
    }
};

Tree_expression_node* build_expression()
{
    Tree_expression_node* operand1=new Tree_expression_node('2');
    Tree_expression_node* operand2=new Tree_expression_node('8');//instead of 10
    Tree_expression_node* operand3=new Tree_expression_node('7');
    Tree_expression_node* operand4=new Tree_expression_node('3');
    Tree_expression_node* operand5=new Tree_expression_node('2');
    Tree_expression_node* operand6=new Tree_expression_node('4');
    Tree_expression_node* operator1=new Tree_expression_node('-',operand2,operand3);
    Tree_expression_node* operator2=new Tree_expression_node('*',operand1,operator1);
    Tree_expression_node* operator3=new Tree_expression_node('*',operand5,operand6);
    Tree_expression_node* operator4=new Tree_expression_node('+',operand4,operator3);
    Tree_expression_node* root=new Tree_expression_node('+',operator2,operator4);
    return root;
}
//inorder print left then yourself then right
void inorder_traverse(Tree_expression_node* root,string &res)//2 * 8 - 7 + 3 + 2 * 4
{
    if(root==NULL) return;
    inorder_traverse(root->left,res);
    res+=root->value;
    inorder_traverse(root->right,res);
}
//postorder print left right yourself
void postorder_traverse(Tree_expression_node* root,string &res)//2 8 7 - * 3 2 4 * + +
{
    if(root==NULL) return;
    postorder_traverse(root->left,res);
    postorder_traverse(root->right,res);
    res+=root->value;
}
//pre-order traverse : print yourself left right;
void preorder_traverse(Tree_expression_node* root,string &res)//+ * 2 - 8 7 + 3 * 2 4
{
    if(root==NULL) return;
    res+=root->value;
    preorder_traverse(root->left,res);
    preorder_traverse(root->right,res);
}
int evaluatePostfix(string exp)
{
	stack<int> operand_stack;
	int i;

	// Scan all characters one by one
	for (i = 0; i<exp.size(); ++i)
	{
		// If the scanned character is an operand (number here),
		// push it to the stack.
		if (isdigit(exp[i])) // '1' - '0' = 1 --> 49 - 48
			operand_stack.push(exp[i] - '0');

		//  If the scanned character is an operator, pop two
		// elements from stack apply the operator
		else
		{
			int val1 = operand_stack.top();
			operand_stack.pop();
			int val2 = operand_stack.top();
			operand_stack.pop();
			switch (exp[i])
			{
			case '+': operand_stack.push(val2 + val1); break;
			case '-': operand_stack.push(val2 - val1); break;
			case '*': operand_stack.push(val2 * val1); break;
			case '/': operand_stack.push(val2 / val1); break;
			}
		}
	}
	return operand_stack.top();
}
int main()
{
    string res="";
    Tree_expression_node* root=build_expression();
    postorder_traverse(root,res);
    cout<<res;
    cout<<endl<<evaluatePostfix(res);
    return 0;
}
