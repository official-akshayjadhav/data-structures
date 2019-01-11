#include<iostream>
#define CHIELD 0
#define THREAD 1

using namespace std;

class node{
	public:
		int data;
		node *left;
		node *right;

		bool rf;
		bool lf;
};

class BTtoTBT{

		node *head;

		node *pred; //predecessor node

	public:
		node* createNode(int);
		void getBinaryTree();
		void convertBTtoTBT();
		void make_thread(node *);
		void display();
};

//function to create new node
node* BTtoTBT::createNode(int d){
	node *t = new node;
	t->data = d;
	t->left = t->right = NULL;
	t->lf = t->rf = CHIELD;

	return t;
}

//functio to create binary tree
void BTtoTBT::getBinaryTree(){

	int d;
	char ch;

	while(1){

		if(head == NULL){
			cout<<"Enter data for root : ";
			cin>>d;
			head = createNode(d);
		}

		node * t = head, *prev = head;

		while(t != NULL){

			cout<<"root is :"<<t->data;
			cout<<"\nwhere to go Left or Right (L / R ) : ";
			cin>>ch;

			if(ch == 'R' || ch == 'r'){
				prev = t;
				t= t->right;
			}

			else if(ch == 'L' || ch == 'l'){
				prev = t;
				t= t->left;
			}

			if(ch == 'r' || ch == 'R'){
				cout<<"\nEnter data : ";
				cin>>d;
				prev->right = createNode(d);
			}

			no more;

			if(ch == 'L' || ch == 'l'){
				cout<<"\nEnter data : ";
				cin>>d;
				prev->left = createNode(d);
			}
		}

		cout<<"\nDo you want to add 1 more node (Y/N): ";
		cin>>ch;

		if(ch == 'n'||ch == 'N')
			break;
	}
}




void BTtoTBT::make_thread(node *curr){

	if(curr == NULL)
		return;

	//go to left
	make_thread(curr->left);

	//we are at root nodes

	if(pred != NULL && pred->rf == THREAD){
		pred->right = curr;
	}
	pred = curr;

	//go to right
	make_thread(curr->right);
}

void BTtoTBT::convertBTtoTBT(){
	make_thread(head);
}

void BTtoTBT:: display(){
	node *curr = head;
	node *t = curr;
	while(1){
		//when right is null smply break
		if(curr == NULL)
			break;

		t = curr;
		//go to it's left most
		while(t->left != NULL)
			t = t->left;

		while(t != curr){
			cout<<t->data<<" ";
			t = t->right;
		}
		cout<<t->data<<" ";
		curr = curr->right;
	}
}
