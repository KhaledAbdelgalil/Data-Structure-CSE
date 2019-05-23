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
void test_infix_top_postfix1()
{
	string exp = "(1+2)*(3+2)/2";
	cout << infixToPostfix(exp)<<endl;
	// 12+32+*2/
}
void test_infix_top_postfix2()
{
	string exp = "(A+B)*(C+D)";
	cout << infixToPostfix(exp)<<endl;
	// AB+CD+*
}
void test_infix_top_postfix3()
{
	string exp = "(A+B)*C";
	cout << infixToPostfix(exp)<<endl;
	// AB+C*
}
void test_infix_top_postfix4()
{
	string exp = "A+B*C";
	cout << infixToPostfix(exp)<<endl;
	// ABC*+
}
int main()
{
    test_infix_top_postfix1();
    test_infix_top_postfix2();
    test_infix_top_postfix3();
    test_infix_top_postfix4();
    return 0;
}
