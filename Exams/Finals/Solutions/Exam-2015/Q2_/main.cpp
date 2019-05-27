//if found ( treat it as individual expression till found ) then pop all in stack til (
//to convert infix to postfix will make some helper functions
#include <iostream>
#include<stack>
using namespace std;

bool isOperand(char x)
{
    return (x<='9'&&x>='0')||(x<='Z'&&x>='A');
}
//function to return precedence of operators higher returned number means higher precedence
int precedence(char x)
{
    switch(x)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
    return -1;
}
string infixToPostfix(string expression)
{
    stack<char>operators;
    string result="";
    for(int i=0;i<expression.size();i++)
    {
        //if it's operand put it directly to output
        if(isOperand(expression[i]))
            result+=expression[i];
        else if(expression[i]=='(')
            operators.push(expression[i]);
        else if(expression[i]==')')
        {
            while(!operators.empty()&&operators.top()!='(')
                    {
                        result+=operators.top();
                        operators.pop();
                    }
                    operators.pop();
        }
        else//operator is coming
        {
            while(!operators.empty()&&precedence(expression[i])<=precedence(operators.top()))
            {
                result+=operators.top();
                operators.pop();
            }
            operators.push(expression[i]);
        }
    }
    while(!operators.empty())
    {
       result+=operators.top();
        operators.pop();
    }
    return result;
}
float evaluatePostfix(string expression)
{
	stack<float> operands;


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
			float x = operands.top();
			operands.pop();
			float y = operands.top();
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

void Q2_a()
{
	string exp = "((X-4)*Y+3)/2";
	cout << infixToPostfix(exp)<<endl;
	// 12+32+*2/
}

void Q2_b()
{

	cout << evaluatePostfix("84-2*3+2/")<<endl;//assume 10 is 8
}
int main()
{
    Q2_b();
    return 0;
}
