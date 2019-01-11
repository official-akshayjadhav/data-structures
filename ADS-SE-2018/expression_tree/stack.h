#include<vector>

using namespace std;

template <class T>
class stack{
		vector <T> arr;
	public:
		void push(T d){
			arr.push_back(d);
		}
		T top(){
			return arr.back();
		}
		void pop(){
			arr.pop_back();
		}

		bool isEmpty(){
			return arr.empty();
		}

		int size(){
			return arr.size();
		}
};

