#include<iostream>
#include<cmath>
#include<stack>
using namespace std;

float chngFloat(char ch) {
   int val;
   val = ch;
   return float(val-'0');   //it will return float from character
}

int isOperator(char ch) {
   if(ch == '+'|| ch == '-'|| ch == '*'|| ch == '/' || ch == '^')
      return 1;    
   return -1;   
}

int isOperand(char ch) {
   if(ch >= '0' && ch <= '9')
      return 1;   
   return -1;   
}

float operation(int num1, int num2, char op) {
    int result;
   if(op == '+')
   {
       result = num2+num1;
       return result;
   }

   else if(op == '-')
   {
       result = num2-num1;
       return result;
   }
   
   else if(op == '*')
   {
       result = num2*num1;
   }
   else if(op == '/')
   {
       result = num2/num1;
       return result;
   }
   
   else if(op == '^')
   {
        result = pow(num2,num1);
       return result;
   }
      
   else
    return  -1;
}

float postfixEvaluation(string postfix) {
   int num1, num2;
   stack<float> s;
   string::iterator i;

   for(i=postfix.begin(); i!=postfix.end(); i++) {
    
    if(isOperator(*i) != -1) {
        num1 = s.top();
        s.pop();
        num2 = s.top();
        s.pop();
        s.push(operation(num1, num2, *i));

    }

    else if(isOperand(*i) > 0) {
         s.push(chngFloat(*i));
      }
   }
   return s.top();
}

int main() { 
     
   string exp;

   cout << "Enter an Expression : ";
   cin>>exp;
   cout << "The result is: "<<postfixEvaluation(exp);
}