#include<iostream>

//#include"stack.h"
#include"expressionConvertor.h"

#define OPERAND 0
#define OPERATOR 1

using namespace std;


class node{
	public:
		char data;
		node * left;
		node * right;
		bool type;
};


class ExpTree{
		string exp; //original expression string
		node *root;

	public:
		void getExpression(){
			cout<<"Enter infix expression : ";
			cin>>exp;

			//convert to prefix form
			exp = makePrefix(exp);
		}
		node * createNode(char);
		bool isOperator(char ch);
		void makeTree();
		void display(node *);
		node* getRoot(){return root;}
};

bool ExpTree::isOperator(char ch){
	if(!(ch >= 'a' && ch <='z'))
		if(!(ch >= 'A' && ch <= 'Z'))
			if(!(ch >= '0' && ch <= '9'))
				return true;

	//if char is not operator
	return false;
}

node* ExpTree::createNode(char ch){
	node *t = new node;
	t->data = ch;
	t->left = t->right = NULL;
	if(isOperator(ch))
		t->type = OPERATOR;
	else
		t->type = OPERAND;
}

void ExpTree::makeTree(){

	stack <node *> stk;

	node * top1 = NULL, *top2 = NULL, *top3 = NULL;
	node *t;

	int i = 0;
	char token;

	while(exp[i] != '\0'){
		token = exp[i];

		t = createNode(token);
		top2 = top1;
		top1 = t;
		stk.push(t);

		if((t->type != OPERATOR) && (stk.size() >= 2 && top1->type == OPERAND && top2->type == OPERAND)){
			
			stk.pop();
			stk.pop();
			top3 = stk.top();
			stk.pop();

			top3->left = top2;
			top3->right = top1;
			top3->type = OPERAND;

			if(!stk.isEmpty())
				top2 = stk.top();
			else
				top2 = NULL;

			stk.push(top3);
			top1 = stk.top();
			
		}
		i++;
	}

	root = top3;

	while(stk.size() >= 2){

		top1 = stk.top();
		stk.pop();
		top2 = stk.top();
		stk.pop();
		top3 = stk.top();
		stk.pop();

		top3->left = top2;
		top3->right = top1;
		top3->type = OPERAND;

		if(!stk.isEmpty())
			top2 = stk.top();
		else
			top2 = NULL;
		
		stk.push(top3);
		top1 = stk.top();
	}
	root = top3;
}


//infix display
void ExpTree::display(node *t){
	if(t == NULL)
		return;
	display(t->left);
	cout<<"|--->|"<<t->data;
	display(t->right);
}


int main(){

	ExpTree e;
	e.getExpression();
	e.makeTree();

	cout<<"\nInfix tree display : \n";
	e.display(e.getRoot());
	cout<<endl;
	return 0;
}