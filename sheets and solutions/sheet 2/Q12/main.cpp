#include <iostream>
#include<stack>
using namespace std;

int isOperand(char ch)
{
	return (ch >= '0' && ch <= '9');
}
int evaluatePostfix(string expression)
{
	stack<int> operands;


	// Scan all characters one by one
	for (int i = 0; i<expression.size(); ++i)
	{
		// If the scanned character is an operand (number here),
		// push it to the stack.
		if (isOperand(expression[i])) // '1' - '0' = 1 --> 49 - 48
			operands.push(expression[i] - '0');

		//  If the scanned character is an operator, pop two
		// elements from stack apply the operator
		else
		{
			int x = operands.top();
			operands.pop();
			int y = operands.top();
			operands.pop();
			switch (expression[i])
			{
				case '+': operands.push(x + y); break;
				case '-': operands.push(y - x); break;
				case '*': operands.push(y * x); break;
				case '/': operands.push(y / x); break;
			}
		}
	}
	return operands.top();
}
void test_evaluating_postfix_expression()
{
	string exp = "12+32+*2/";
	cout<<evaluatePostfix(exp)<< " should be 7"<<endl;
}
int main()
{
test_evaluating_postfix_expression();
    return 0;
}
