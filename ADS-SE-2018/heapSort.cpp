/*
program to implement heap sort application

ADL lab assignment program no. 21

prog :  Read the marks obtained by students of second year in an online examination of particular
        subject. Find out maximum and minimum marks obtained in that subject. Use heap data
        structure. Analyze the algorithm.
*/

#include <iostream>
#include <vector>

using namespace std;

class StuMarkAnalysis{

    std::vector<int> mrk;
    int arr_size;

  public:

    //method to get no. of students and their marks from user
    void getMarks(){
      cout<<"\nEnter no of students : ";
      cin>>arr_size;
      arr_size++;
      int m;

      mrk.push_back(arr_size-1);
      cout<<"\nEnter marks for "<<arr_size<<"students \n";

      for(int i = 0; i < arr_size-1 ; i++){
        cin>>m;
        mrk.push_back(m);
      }
    }

    //method to display students marks
    void display(){
      if(arr_size == 0){
        cout<<"\nno marks available !";
        return;
      }

      cout<<"\nMarks of students : \n";
      for(int i = 1; i < arr_size ; i++){
        cout<<mrk[i]<<" ";
      }
    }

    void swap(int a, int b){
      int tmp = mrk[a];
      mrk[a] = mrk[b];
      mrk[b] = tmp;
    }


    void heapify(int parent_index, int arr_size){


      //return when parent index get out of bound
      if( parent_index >= arr_size )
        return;

      int lcindex = parent_index * 2 ;  //calculating left chield index

      //if lef chield is not present then right also not present because of complete binary tree rule
      //so no element to compare in this heap
      //so simply return :)
      if ( lcindex >= arr_size )
        return;

      //else left is present
      if( mrk[parent_index] < mrk[lcindex] ){
        swap(parent_index, lcindex);
        heapify(lcindex, arr_size);
      }

      int rcindex = (parent_index * 2) + 1 ;  //calculating right chield index
      //check whether right element is present or not
      if ( rcindex >= arr_size )
        return;

      //else right is present
      if( mrk[parent_index] < mrk[rcindex] ){
        swap(parent_index, rcindex);
        heapify(rcindex, arr_size);
       }
    }

    //method to sort marks in ascending order usign head data structure
    void sort(){
      int i = arr_size/ 2; //getting last parent index position
      int j = i;

      int size = arr_size;
      for(; j> 0 && size > 0; j--){
        i = j;
        for(; i > 0 ; i-- )
          heapify(i, size);
        size--;
        swap(1, size); //placing top element to last;
      }
    }
};

int main(){
  StuMarkAnalysis s;
  s.getMarks();
  s.sort();
  s.display();

  return 0;
}
