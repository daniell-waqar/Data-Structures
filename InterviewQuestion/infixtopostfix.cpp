#include<bits/stdc++.h>
using namespace std;


class stack
{
    private:
    // int size;
    char top;
    int *arr;
    
    

    public:

    stack( )
    {
        
       
        // size = 5;
        arr = new string [size];
        top = -1;

    }

    void push(int val)
    {   
        if(top == size-1)
            cout << "Stack overflow!";
        else
        {
            top++;
            arr[top] = val;
        }
    }
    

    int pop()
    {   
        if(top == -1)
            cout << "Stack underflow!";
        else{
        int val = arr[top];
        top--;
        return val;
        }

    }

    bool isEmpty()
    {
        if(top == -1)
            return true;
        return false; 
    }

    void display()
    {   
        if(isEmpty())
        {
            return;
        }
        else
        {

            for(int i = top; i>=0; i--)
            {
                cout <<arr[i]<< " ";
                
            }
        }
       
    }

    int peek()
    {
        return arr[top];
    }



// A Function to convert infix expression to postfix expression
string infixToPostfix(string s1) {

	
	string ans = "";

	for (int i = 0; i < s1.length(); i++) {
		char ch = s1[i];

		// If the current character is an operand, add it to our answer string.
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
			ans += ch;   // Append the current character of string in our answer

		// If the current character of string is an '(', push it to the stack.
		else if (ch == '(')
			push('(');

		// If the current character of string is an ')', append the top character of stack in our answer string
		// and pop that top character from the stack until an '(' is encountered.
		else if (ch == ')') {
			while (peek() != '(')
			{
				ans += top();    // Append the top character of stack in our answer
				pop();
			}
			pop();
		}

		//If an operator is scanned
		else {
			while (!empty() && prec(s1[i]) <= prec(top())) {
				ans += top();
				pop();
			}
			push(ch);             // Push the current character of string in stack
		}
	}

	// Pop all the remaining elements from the stack
	while (!empty()) {
		ans += top();
		pop();
	}

	return ans;
}

// A Function to return precedence of operators
int prec(char ch) {
	if (ch == '^')
		return 3;
	else if (ch == '/' || ch == '*')
		return 2;
	else if (ch == '+' || ch == '-')
		return 1;
	else
		return -1;
}



};


int main() {
	string s;
	cin >> s;
	cout << infixToPostfix(s);
    stack st;
    s1.push(4);
    s1.push(3);
    s1.push(1);
    s1.display();
    s1.pop();
    cout << endl;
    s1.display();
    cout << endl;


	return 0;
}