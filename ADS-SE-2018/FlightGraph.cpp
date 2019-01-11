//prog : Flight Graph program Assignment no. 5

#include<iostream>
#include<vector>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;

class FlightGraph{	
		//vector< vector<int> >  matrix;
		int matrix [100][100];
		vector< string > citynames;
		int n; // no of citynames
	public:
			FlightGraph(){
				n = 0 ;
			}

			void init(){
				cout<<"\nEnter number of citynames : ";
				cin>>n;

				cout<<"\nEnter names of "<<n<<" citynames :\n";
				for(int i=0;i < n ; i++){
					
					string str;
					cin>>str;
					citynames.push_back(str);

					for(int j = 0 ; j < n; j++)
						matrix[i][j] = 0;
				}
			}
			int searchInd(string);
			void addRecord();
			void display();
};

int FlightGraph::searchInd(string s){
	int i = -1;
	while((i+1)< citynames.size())
		if(citynames[++i] == s)
			return i;

	return -1;
}
void FlightGraph::addRecord(){

	int d;
	string source , dest;
	cout<<"\nEnter new record data :\nEnter source city :";
	cin>>source;

	cout<<"\nEnter destination city :";
	cin>>dest;

	cout<<"\nEnter distance in km :";
	cin>>d;

	int i = searchInd(source); 
	if( i==-1)
	{
		cout<<"\ninvlalid source city name !";
		return ;
	}
	int j = searchInd(dest); 
	if( i==-1)
	{
		cout<<"\ninvlalid destination city name !";
		return ;
	}

	matrix[i][j] = d;
	matrix[j][i] = d;
}


void FlightGraph::display()
{
		int cnt = 0;
		if(n ==0)
		{
			cout<<"\nNo citynames found !";
			cout<<"add citynames first";
		}
		cout<<"\nFlight path recoeds with distance (km) :\n";

		for(int i = 0;i<n;i++){
			for(int j = 0; j< n;j++){
				if(matrix[i][j] != 0){
					cout<<citynames[i]<<"-->"<<citynames[j]<<" : "<<matrix[i][j]<<endl;
					cnt++;
				}
			}
		}

		if(cnt ==0)
			cout<<"No records found !";
}

int menu(){
	cout<<"\nFlight info recorder \n\n ";
	cout<<"\n0. init graph\n1.add recordd\n2. display\n3.exit\nEnter choice : ";

	int opt;
	cin>>opt;

	return opt;
}

int main(){

	FlightGraph f;
	int opt;
	while(1){
		system("clear");
		opt = menu();

		switch(opt){
			case 0:
				f.init();
				break;
			case 1:
				f.addRecord();
				break;
			case 2:
				f.display();
				break;
			case 3:
				return 0;
			default:
				cout<<"invalid choice ! try again";
				break;
		}
		getchar();
		getchar();
	}
	return 0;
}		
