#include<iostream>

using namespace std;

int min(int a,int b){return (a<=b)?a:b;}

int  fibonacci(int* arr,int n,int x)
{
	//comparing last element 
	if(arr[n-1]==x)
		return n-1;

	//assigning fibonacci values to var : fibM2 ,fibM1 ,fibM 
	int fibM,fibM1,fibM2;

	fibM1=1,fibM2=1;
	fibM=fibM1+fibM2;
	while(fibM<n)
	{
		fibM2=fibM1;
		fibM1=fibM;
		fibM=fibM1+fibM2;
	}

	//initiating  offset=-1
	int i=0;
	int offset=-1;

	//search element in arry till greater fibM greter than 1
	while(fibM>1)
	{
		i=min(offset+fibM2,n-1);

		if(arr[i]<x)
		{
			fibM=fibM1;
			fibM1=fibM2;
			fibM2=fibM-fibM1;
			offset=i;
		}
		else if(arr[i]>x)
		{
			fibM=fibM2;
			fibM1=fibM1-fibM;
			fibM2=fibM-fibM1;
		}

		//element not foundn :)
		else 
			return i;
	}

	//element not found :|
	return -1;
}


int main()
{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];

		int x;
		cin>>x;

		cout<<"pos (-1 for not found) : "<<fibonacci(arr,n,x)<<endl<<endl;

		return 0;
}