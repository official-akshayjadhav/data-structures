/*
prog :	to implement selection sort
		for int val.
*/

#include<iostream>
#include<vector>

using namespace std;

class SelectionSort
{
		vector<int> vec;
		int size;
	public:
		SelectionSort()
		{
			size=10;
			//vec=new vector<int>(10);
		}
		SelectionSort(int  n)
		{
			size=n;
			//vec=new vector<int>(n);
		}

		void getData();
		void display();
		void sort();
		void swap(int,int);

};

void SelectionSort::getData()
{
	cout<<"\nEnter "<<size<<" elements :\n";
	int d;
	for(int i=0;i<size;i++)
	{

		cin>>d;
		vec.push_back(d);
	}
	return;
}

void SelectionSort::display()
{
	cout<<"\nData elements :\n";
	for(int i=0;i<size;i++)
		cout<<vec[i]<<" ";
	return;
}

void SelectionSort::swap(int a,int b)
{
	vec[a]=vec[a]+vec[b];
	vec[b]=vec[a]-vec[b];
	vec[a]=vec[a]-vec[b];
}

void SelectionSort::sort()
{
	int i,j,tmp;
	for(i=0;i<size-1;i++)
	{
		tmp=i;
		for(j=i+1;j<size;j++)
		{
			if(vec[tmp]>vec[j])
				tmp=j;
		}
		if(i!=tmp)
		{
			swap(i,tmp);
		}
	}
}


int main()
{
	SelectionSort s;
	s.getData();
	s.display();
	s.sort();
	s.display();

	return 0;
}