#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<queue>

using namespace std;

class node
{
       public:
	       int data;
	       node * left;
	       node * right;
};


class BST
{
		node* root ;
		int count;

	public:
		void init();
		node* createNode(int);

		node* getRoot(){return root;}
		void setRoot(node * r){root = r;}

		void createTree(int arr[], int n);
		void insert(node * , int);
		int nodeCount();
		void display(node *);
		int minVal(node*);
		node* swap(node *t1, node *t2);
		int longestPath(node *);
};

void BST::init()
{
	root = NULL;
	count = 0;
}


node* BST::createNode(int d)
{
	node * tmp = new node;
	tmp->data =d;
	tmp->left = tmp->right = NULL;

	return tmp;
}

void BST::createTree(int arr[], int n){

   if(n ==0){
       cout<<"\nArray is empty !";
       return;
   }

   root = createNode(arr[0]);
   count++;
   int i = 1;
   node * t;
   while(i < n ){

	node * tmp = createNode(arr[i]);
	count++;
	t = root;

	while(1){

		if(t->data > arr[i]){
			if(t->left == NULL)
				break;

			t = t->left;
			continue;
		}

		else{
			if(t->right == NULL)
				break;

			t = t->right;
			continue;
		}
	}

	if(t->data > arr[i])
		t->left = tmp;
	else
		t->right = tmp;

   	i++;
   }
}


void BST::insert( node * r, int data )
{
	count++;

	if(r == NULL)
	{
		root = createNode(data);

		return;
	}
	else
	{
		if( r->data > data )
		{
			if( r->left == NULL)
				r->left = createNode(data);


			else
				insert(r->left, data);
		}

		else if(data >= r->data)
		{
			if(r->right == NULL)
				r->right = createNode(data);


			else
				insert(r->right, data);
		}
	}
}


void BST::display(node * r)
{
	if(r == NULL)
		return;

	cout<<r->data<<"  ";

	display(r->left);
	display(r->right);
}

int BST::nodeCount(){return count;}


bool search(node * r , int sv)
{
	static node *p = NULL;
	if(r == NULL)
		return false;

	if(r->data == sv)
	{
		cout<<"found\ndata :"<<r->data;

		if(p != NULL)
			cout<<"\nParent data :"<<p->data;
		return true;
	}

	else
	{
		if( r->data > sv )
		{
			if( r->left == NULL)
				return false;

			else{
				p = r;
				return search(r->left, sv);
			}
		}

		else if(sv >= r->data)
		{
			if(r->right == NULL)
				return false;

			else{
				p = r;
				return search(r->right, sv);
			}
		}
	}

	return false;
}

void BFSdisplay(){

	queue <node *> que;



}

int BST::minVal(node* r)
{
	if(r == NULL)
		return -1;
	else
		while(r->left !=NULL)
			r = r->left;
	return r->data;
}

node* BST::swap(node *t1, node *t2){
	 if(t1 ==NULL)
	 	return NULL;

	 t2 = createNode(t1->data);

	 t2->right = swap(t1->left, t2->right);
	 t2->left = swap(t1->right, t2->left);

	 return t2;
}

int BST::longestPath(node *t)
{
	static int count= 1, max = 1;

	if(t->left == NULL && t->right == NULL)
	{
		if(count > max)
			max = count;

		return max;
	}

	if(t->left != NULL)
	{
		count++;
		longestPath(t->left);
		count--;
	}
	if(t->right != NULL)
	{
		count++;
		longestPath(t->right);
		count--;
	}
	return max;
}

int main()
{
	BST b;
	BST b2; // to store swapped tree

	int d;
	b.init();
	int *arr, n=0;

	while(1)
	{
		system("clear");

		cout<<"\n\n*****************************************************";
		cout<<"\nMENU\n0. create tree\n1.insert\n2.display\n3.node count\n4.search \n5. min val \n6. swap\n7. longest path\nchoose option : ";
		int ch;
		cin>>ch;

		switch(ch)
		{
			case 0:
				cout<<"\nEnter Initial data \nEnter no of elements :";
				cin>>n;
				arr = new int[n];
				cout<<"\nEtner data :\n";
				for(int i=0;i<n;i++)
					cin>>arr[i];
				b.createTree(arr,n);
				break;

			case 1:
				cout<<"\nEnter data :";
				cin>>d;
				b.insert(b.getRoot(), d);
				break;

			case 2:
				cout<<"Tree Data in prefix : ";
				b.display(b.getRoot());
				cout<<endl;
				break;
			case 3:
				cout<<"\nNumber of nodes : "<<b.nodeCount();
				break;
			case 4:
				cout<<"\nEnter sv :";
				cin>>d;
				if(!search(b.getRoot(), d))
					cout<<"\nNot found !";
				break;
			case 5:
				d=b.minVal(b.getRoot());
				if(d==-1)
					cout<<"\nTree Empty !";
				else
					cout<<"\nMin val :"<<d;

				break;
			case 6:

				b2.setRoot(b.swap(b.getRoot(),b2.getRoot()));

				cout<<"\nMirror inamge :\n";
				b2.display(b2.getRoot());
				break;

			case 7:
				cout<<"lobgest path :"<<b2.longestPath(b.getRoot());
				break;
			default :
				goto exit;
		}
		getchar();getchar();
	}
	exit:
	return 0;

}
