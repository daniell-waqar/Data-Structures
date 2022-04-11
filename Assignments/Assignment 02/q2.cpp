
#include<iostream>
#include<stack>
using namespace std;

// Function to check whether two characters are open 
// and close of same type. 
bool pairs(char open,char close)
{
	if(open == '(' && close == ')') 
        return true;

	else if(open == '{' && close == '}') 
        return true;

	else if(open == '[' && close == ']') 
        return true;
    else
	    return false;
}
bool checkParaenthesis(string str)
{
	stack<char>  s;
	for(int i =0;i<str.length();i++)
	{
		if(str[i] == '(' || str[i] == '{' || str[i] == '[')
			s.push(str[i]);
		else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
			if(s.empty() || !pairs(s.top(),str[i]))
				return false;
			else
				s.pop();
		}
	}
	return s.empty() ? true:false;
}

int main()
{
	
	string exp;
	cout<<"Enter an string:  ";       //given string by default stoed in Char Array
	cin>>exp;
	bool res = checkParaenthesis(exp);

    if(res)
		cout<<"Given string is Balanced" << endl;
	else
		cout<<"Given string is Not Balanced" << endl;
}