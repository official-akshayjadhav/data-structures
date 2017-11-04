// prog : sparse matrix
// realozation , transpose, fast transpose, addition of two mat.

#include<iostream>

#define MAX 3

using namespace std;

//structure to define row of sparse mat.
struct sparse
{
	int r,c,v;  //row col val
};


//class : to organize sparse mat(matrix).
class SparseMat
{
	private:
		sparse *spr;
		int size;

	public:
			SparseMat(){size=0;}
			void init(int);
			void getData();
			void display(string);
			void transpose();
			void fastTranspose();
			void operator = (SparseMat); //assign 1 spr mat to another
 			SparseMat operator + (SparseMat & s2); //opr. ovr. for addition of 2 mat.
};

//initialize size to spr mat array
void SparseMat::init(int s)
{
	
	size=s;

	//allocating size to sparse mat
	spr=(sparse *)malloc(sizeof(sparse)*size);
	return;
}

void SparseMat::getData()
{
	int m,n,i=0,j=0,d;
	int k=0; //sparse mat traversal

	cout << "enter size of matrix (m X n) :";
	cin>>m>>n;

	//set initial size to spr mat array
	init((m*n/2));
	
	//accept all mat. and store non zero ele. in sparse mat
	for(i;i<m;i++)
		for(j=0;j<n;j++)
		{
			cin>>d;

			if(d!=0)
			{
				spr[k].r=i;
				spr[k].c=j;
				spr[k++].v=d;
			}
		}

	size=k;
}

void SparseMat::display(string s)
{
	if(size==0)
	{
		cout<<"\nsparse matrix is empty !"<<endl;
		return;
	}
	cout<<"Sparse mat "<<s<<" : \nrow\tcol\tval\n";
	for(int i=0;i<size;i++)
		cout<<spr[i].r<<"\t"<<spr[i].c<<"\t"<<spr[i].v<<endl;
}

void SparseMat::operator = (SparseMat s2)
{
	init(s2.size);
	int i=0;
	while(i<size)
	{	
		this->spr[i].r=s2.spr[i].r;
		spr[i].c=s2.spr[i].c;
		spr[i].v=s2.spr[i].v;
		i++;
	}
}

SparseMat SparseMat::operator + (SparseMat &s2)
{
	SparseMat tmp;
	int i=0,j=0,k=0;

	tmp.init(size+s2.size);

	while(i<size && j<s2.size)
	{
		if(spr[i].r < s2.spr[j].r||(spr[i].r == s2.spr[j].r && spr[i].c < s2.spr[j].c))
		{
			tmp.spr[k].r=spr[i].r;
			tmp.spr[k].c=spr[i].c;
			tmp.spr[k++].v=spr[i].v;
			i++;
		}
		else if(spr[i].r > s2.spr[j].r||(spr[i].r == s2.spr[j].r && spr[i].c > s2.spr[j].c))
		{
			
			tmp.spr[k].r=s2.spr[j].r;
			tmp.spr[k].c=s2.spr[j].c;
			tmp.spr[k++].v=s2.spr[j].v;
			j++;
		}
		else
		{
			

			tmp.spr[k].r=spr[i].r;
			tmp.spr[k].c=spr[i].c;
			tmp.spr[k++].v=spr[i].v+s2.spr[j].v;
			i++;j++;
		}
	}
	while(i<size)
	{
		tmp.spr[k].r=spr[i].r;
		tmp.spr[k].c=spr[i].c;
		tmp.spr[k++].v=spr[i].v;
		i++;
	}

	while(j<s2.size)
	{
		tmp.spr[k].r=spr[j].r;
		tmp.spr[k].c=spr[j].c;
		tmp.spr[k++].v=spr[j].v;
		j++;
	}
	
	tmp.size=k;

	return tmp;
}

int menu()
{
	int opt;

	cout<<"\nsparse Matrix Menu :\n";
	cout<<"1.add data for mat 1\n2.dispay mat 1\n3.add data for mat 2\n4.dispay mat 2\n5.Addition";
	cout<<"choose opt : ";
	cin>>opt;

	return opt;
}

int main()
{
	SparseMat s1,s2,s3;

	while(1)
	{
		switch(menu())
		{
			case 1:
				s1.getData();
					break;
			case 2:
				s1.display("s1");
				break;
			case 3:
				s2.getData();
				break;
			case 4:
				s2.display("s2");
				break;
			case 5:
				s3=s1+s2;
				cout<<"now display ";
				s3.display("s3");
				break;
			default :
				return 0;
		}
	}
	return 0;
}