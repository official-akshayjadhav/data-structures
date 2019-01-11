/*
program : 	A book consists of chapters, chapters consist of sections and sections consist of subsections.
			Construct a tree and print the nodes. Find the time and space requirements of your method.

date : 20-01-2018

*/

#include<iostream>
#include<string.h>
#include<stdlib.h>

#define DATA 0
#define DL 1

using namespace std;

//node structure
class node{
       public:	
              bool flg;
       	//string type; 	//type of name data
	       string nm;	//name
	       node *dl;		//pointer to down link
	       node *next;		//pointer to next node
}; 


class Book{
		node * head;  // pointer to whole book structure

	public:
		Book(){head = NULL;} //initialize head to null

		node* createNode(string nm);
              node* createNode(node *); 
              
		void insertSubSection(node *t);
		void insertSection(node *t);
		void insertChapter(node *t);
		void insertBook();
		void insert();
		void display();
		void delNode();
		void insNode();
};

node* Book::createNode(string nm){
	node  *t = new node;

	t->flg = DATA;
	t->nm = nm;
	t->dl = t->next = NULL;

	return t;
}

node* Book::createNode(node *dl){
	node  *t = new node;

	t->flg = DL;
	t->nm ="";
	t->dl = dl;
	t->next = NULL;

	return t;
}


void Book::insertSubSection(node *t){
	 
	cout<<"\n\t\t\tEnter name of Sub Section : ";
	string nm = "";
	
	cin>>nm;

	if(nm == "nil")
		return;

	node *p = createNode(nm);

	if(t->dl == NULL){
		t->dl = p;
	}
	
	else{
		node *tmp = t->dl;
		while(tmp->next != NULL)
			tmp = tmp->next;

		tmp->next = p;
	}

	insertSubSection(t);
}

void Book::insertSection(node *t){
	
	 
	cout<<"\n\t\tEnter name of section : ";
	string nm = "";
	cin>>nm;
	if(nm == "nil")
		return;

	node *p = createNode(nm);

	if(t->dl == NULL){
		t->dl = p;
	}
	
	else{
		node *tmp = t->dl;
		while(tmp->next != NULL)
			tmp = tmp->next;

		tmp->next = p;
	}

	//insert sub sections
	cout<<"\n\t\t\tEnter sub sections for chapter "<<p->nm<<"...\n";
	node *q = createNode(NULL); //down link node
	p->next = q;
	insertSubSection(q);

	insertSection(t);	
}

void Book::insertChapter(node *t){
	 
	
	cout<<"\n\tEnter name of new chapter : ";
	string nm = "";
	cin>>nm;

	if(nm == "nil")
		return;

	node *p = createNode(nm);

	if(t->dl == NULL){
		t->dl = p;
	}

	else{
		node * tmp = t->dl;
		while(tmp->next != NULL)
			tmp = tmp->next;

		tmp->next = p;
	}
	//insert sections
	cout<<"\n\t\tEnter sections for chapter "<<p->nm<<" ...\n";
	
	node *q = createNode(NULL); //down link node
	p->next = q;
	
	insertSection(q);

       
	insertChapter(t);
}


void Book::insertBook(){
	
	//creating new node
	cout<<"\nEnter name of book : ";
	string nm;
	cin>>nm;
	node *p = createNode(nm);

	//if empty
	if(head == NULL){
		head = p;
	}

	//if not empty
	else{
		node *tmp = head;
		while(tmp->next != NULL)
			tmp = tmp->next;

		tmp->next = p;
	}

	cout<<"\n\tEnter chapters for book "<<p->nm<<" ...\n";
	node *q = createNode(NULL); //down link node
	p->next = q;
	
	insertChapter(q);


	return;
}

void Book::display(){
	node * t = head;

	if(head == NULL){
		cout<<"\nno book to display !";

		return;
	}

	int n1 = 1, n2 = 1, n3 = 1; 
	while(t != NULL){
		
		cout<<"\n\nBOOK name : "<<t->nm;
		
		if(t->next->flg == DATA)
	       {
	              t =t->next;
	              continue;
	       }	
	 
		node *p = t->next;
		p = p->dl;
		 
		
		n1 = 0;
		while(p != NULL){
			cout<<"\n"<<++n1<<". "<<p->nm; //chapter
			
			if(p->next->flg == DATA)
	              {
	                     p =p->next;
	                     continue;
	              }	
	 
		       node *q = p->next;
		       q = q->dl;

			n2=0;

			while(q != NULL){
				cout<<"\n\t-----> "<<n1<<"."<<++n2<<". "<<q->nm;  //section
				
				if(q->next->flg == DATA)
	                     {
	                            q =q->next;
	                            continue;
	                     }	
	        
		              node *r = q->next;
		              r = r->dl;
		              
				n3=0;

				while(r != NULL){
					cout<<"\n\t\t|-----> "<<n1<<"."<<n2<<"."<<++n3<<". "<<r->nm;    //sub section
					r = r->next;
				}
				cout<<endl;
				q = q->next->next;
			}  
			cout<<endl;
			p = p->next->next;

		}
		cout<<endl;

		t = t->next->next;;
	}
	cout<<"\n";
}


//fun to delete the node
void Book::delNode(){
	string type,subnm,secnm,chnm,bnm;

	cout<<"\nchoose type of object \n1.book\t2.chapter\t3.section\t4.sub section\nchoose : ";
	int opt;
	cin>>opt;

	switch(opt){
		case 1:
			type = "book";
			break;
		case 2:
			type = "chapter";
			break;
		case 3:
			type = "section";
			break;
		case 4:
			type = "sub section";
			break;
		default:
			cout<<"\nWrong choice !";
			return;
	}
 

	 
	if(type == "book")
		goto l4;
	else if(type == "chapter")
		goto l3;
	else if(type == "section")
		goto l2;
	else if(type == "sub section")
		goto l1;


	l1:
		subnm = "";
		cout<<"\nEnter sub section name : ";
		cin>>subnm;
	l2:
		secnm = "";
		cout<<"\nEnter section name : ";
		cin>>secnm;
	l3:
		chnm = "";
		cout<<"\nEnter chapter name : ";
		cin>>chnm;
	l4:
		bnm = "";
		cout<<"\nEnter book name : ";
		cin>>bnm;


	node *t = head;  //traversal
	node *p = t;     //previous node handler

	while(t != NULL){
		if(t->nm == bnm)
			break;
		p = t;
		t = t->next;
		if(t != NULL && t->flg == DL){
			p = t;
			t = t->next;
		}
	}
	
	//node NOT found
	if(t == NULL){
		cout<<"\nbook name not found !";
		return;
	}

	//else Book Data FOUND
	if(type != "book"){
		//find chapter
		if(t->next->flg == DL){
			p = t;
			t = p->next->dl;

			while(t != NULL){
				if(t->nm == chnm)
					break;
				p = t;
				t = t->next;
				if(t != NULL && t->flg == DL){
					p = t;
					t = t->next;
				}
			}
		}
		else
			t = NULL;

		//chapter NOT found
		if(t == NULL){
			cout<<"\nchapter name not found !";
			return;
		}

		if(type != "chapter"){
			//find section
			if(t->next->flg == DL){
				p = t;
				t = p->next->dl;

				while(t != NULL){
					if(t->nm == secnm)
						break;
					p = t;
					t = t->next;
					if(t != NULL && t->flg == DL){
						p = t;
						t = t->next;
					}
				}
			}
			else
				t = NULL;
			//node NOT found
			if(t == NULL){
				cout<<"\nsection name not found !";
				return;
			}

			if(type != "section"){
				//find sub section
				if(t->next->flg == DL){
					p = t;
					t = p->next->dl;

					while(t != NULL){
						if(t->nm == subnm)
							break;

						p = t;
						t = t->next;
					}
				}
				else
					t = NULL;
				//node NOT found
				if(t == NULL){
					cout<<"\nsub section name not found !";
					return;
				}
			}
		}

	}

	if(t == head)
		head = (t->next != NULL)? t->next->next : t->next;
	
	else{

		if(p->next->dl == t){
			p->next->dl = (t->next != NULL )? ((t->next->flg == DL)?t->next->next : t->next ): NULL;
			
			/*if(p->next->dl == NULL){
				node *tmp = p->next;
				p->next = tmp->next;
				cout<<"p->next = "<<p->next;
				delete(tmp);
			}*/
		}
			
		else
		{
			p->next = (t->next != NULL )? ((t->next->flg == DL)?t->next->next : t->next ): NULL;
		}
	}

	cout<<t->nm;
	delete(t);
	cout<<"deletion successfully !";
	return;
}

//fun to insert the node
void Book::insNode(){
	string type,subnm,secnm,chnm,bnm;

	cout<<"\nchoose type of object \n1.book\t2.chapter\t3.section\t4.sub section\nchoose : ";
	int opt;
	cin>>opt;

	switch(opt){
		case 1:
			type = "book";
			break;
		case 2:
			type = "chapter";
			break;
		case 3:
			type = "section";
			break;
		case 4:
			type = "sub section";
			break;
		default:
			cout<<"\nWrong choice !";
			return;
	}

	if(type == "chapter")
		goto l4;
	else if(type == "section")
		goto l3;
	else if(type == "sub section")
		goto l2;


	l2:
		secnm = "";
		cout<<"\nEnter section name : ";
		cin>>secnm;
	l3:
		chnm = "";
		cout<<"\nEnter chapter name : ";
		cin>>chnm;
	l4:
		bnm = "";
		cout<<"\nEnter book name : ";
		cin>>bnm;

  
  	node *t = head;  //traversal
	node *p = t;     //previous node handler

	if(type == "book"){
		
		insertBook();
		return;	
	}

	while(t != NULL){
		if(t->nm == bnm)
			break;
		p = t;
		t = t->next;
		if(t != NULL && t->flg == DL){
			p = t;
			t = t->next;
		}
	}
	
	//node NOT found
	if(t == NULL){
		cout<<"\nbook name not found !";
		return;
	}

	if(type == "chapter"){
		//insertChapter
		node *q;
		if(t->next == NULL || t->next->flg == DATA){
			q = createNode(NULL); //down link node
			q->next = t->next;
			t->next = q;
		}
		else
			q = t->next;

		insertChapter(q);
		return;
	}
	//find chapter
	if(t->next->flg == DL){
		p = t;
		t = p->next->dl;

		while(t != NULL){
			if(t->nm == chnm)
				break;
			p = t;
			t = t->next;
			if(t != NULL && t->flg == DL){
				p = t;
				t = t->next;
			}
		}
	}
	else
		t = NULL;

	//chapter NOT found
	if(t == NULL){
		cout<<"\nchapter name not found !";
		return;
	}

	if(type == "section"){
		//insert section
		node *q;
		if(t->next == NULL || t->next->flg == DATA){
			q = createNode(NULL); //down link node
			q->next = t->next;
			t->next = q;
		}
		else
			q = t->next;

		insertSection(q);
		return;
	}
	//find section
	if(t->next->flg == DL){
		p = t;
		t = p->next->dl;

		while(t != NULL){
			if(t->nm == secnm)
				break;
			p = t;
			t = t->next;
			if(t != NULL && t->flg == DL){
				p = t;
				t = t->next;
			}
		}
	}
	else
		t = NULL;
	//node NOT found
	if(t == NULL){
		cout<<"\nsection name not found !";
		return;
	}
	if(type == "sub section"){
		//insert sub section
		node *q;
		if(t->next == NULL || t->next->flg == DATA){
			q = createNode(NULL); //down link node
			q->next = t->next;
			t->next = q;
		}
		else
			q = t->next;

		insertSubSection(q);
	}
	 
	cout<<"insertion successfully !";
	return;
}


int menu(){
	cout<<"\nBook Menu\n1.Add Book\n2.display\n3.del node\n4.insert node\nChoose Option : ";
	int opt;
	cin>>opt;
	return opt;
}

int main(){
	Book b;
	int opt = 0;
	while(true){
		//system("clear");

		
		opt = menu();

		switch(opt){
			case 1:
				b.insertBook();
				break;
			case 2:
				b.display();
				break;
			case 3:
				b.delNode();
				break;

			case 4:
				b.insNode();
				break;

			default:
				goto exit;
		}
		getchar();
		getchar();
	}
	exit:
	return 0;
}
