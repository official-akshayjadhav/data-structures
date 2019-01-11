#include<iostream>
#include<vector>
#include<string.h>

#include"stack.h"


using namespace std;

//method to reverse string
void reverse(string &str){

	int i=0, j = str.size()-1;
	char ch;

	while(i<j){
		ch = str[i];
		str[i] = str[j];
		str[j] = ch;

		if(str[i] == ')')
			str[i] = '(';
		else if(str[i] == '(')
			str[i] = ')';

		if(str[j] == ')')
			str[j] = '(';
		else if(str[j] == '(')
			str[j] = ')';

		i++;
		j--;
	}
	cout<<"rev : "<<str<<endl;
}

bool isOperator(char ch){
	if(!(ch >= 'a' && ch <='z'))
		if(!(ch >= 'A' && ch <= 'Z'))
			if(!(ch >= '0' && ch <= '9'))
				return true;

	//if char is not operator
	return false;
}

bool isAlphaDig(char ch){
	if((ch >= 'a' && ch <='z'))
		return true;
	else if((ch >= 'A' && ch <= 'Z'))
		return true;
	else if((ch >= '0' && ch <= '9'))
		return true;
	
	return false;
}

//method to return preedence
int precedence(char ch){

	switch(ch){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
		case '%':
			return 2;
		case '^':
			return 3;
		case '(':
			return 4;
	}
	return -1; //invalid operator
}


static string makePrefix(string str){
	
	char token;
	int i = 0;
	string postStr = "";

	stack <char> stk;

	reverse(str);

	while(str[i] != '\0'){
		
		token = str[i];

		if(isAlphaDig(token)){
			postStr = postStr + token ;
		}
		else if(isOperator(token)){
			if(token == ')'){
				while(stk.top() != '('){
					postStr = postStr + stk.top();
					stk.pop();
				}
				stk.pop();
			}
			else if((!stk.isEmpty() && stk.top()!= '(') && precedence(stk.top()) >= precedence(token)){
				while(!stk.isEmpty() && (stk.top()!= '(') && precedence(stk.top()) >= precedence(token)){
					postStr = postStr + stk.top();
					stk.pop();
				}
				stk.push(token);
			}
			else{
				stk.push(token);
			}
		}
		else{
			cout<<"\nerror : expression mismatch !";
		}

		i++;
	}

	while(!stk.isEmpty()){
		postStr = postStr + stk.top();
		stk.pop();
	}

	reverse(postStr);

	return postStr;
}


//for checkin purpose 
int main(){
	string str = "(a*b)+c/d-(e*f)";

	str = expressionConvertor.makePrefix(str);
	cout<<"\npre : "<<str<<endl;

	return 0;
}
