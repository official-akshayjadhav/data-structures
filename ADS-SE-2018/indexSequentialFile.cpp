/*
program : Company maintains employee information as employee ID, name, designation and salary.
          Allow user to add, delete information of employee. Display information of particular
          employee. If employee does not exist an appropriate message is displayed. If it is, then the
          system displays the employee details. Use index sequential file to maintain the data.
*/

#include<iostream>
#include<vector>
#include<string.h>
#include<stdlib.h>

using namespace std;

class EmployeeRecord{
  public:
    int id;
    string name;
    string designation;
    float salary;
    bool status;
};

class EmployeeDatabase{
      vector <EmployeeRecord> db;
      string file_name;
    public:
      void add_record();
      void delete_record(int id);
      void open_file();
      void close_file();
      EmployeeRecord search_record_byID(int);
      EmployeeRecord search_record_byName(string nm);
      void display_record(EmployeeRecord er);
      void display_all(); //it will display all records present in db object
};


//method ot search records by number
EmployeeRecord EmployeeDatabase::search_record_byID(int id){

    for(int i = 0 ; i < db.size() ; i++){
      if(db[i].id == id)
        return db[i];
    }
    EmployeeRecord e;
    e.id = -1;
    return e;
}

//method ot search records by name
EmployeeRecord EmployeeDatabase::search_record_byName(string name){

    for(int i = 0 ; i < db.size() ; i++){
      if(db[i].name == name)
        return db[i];
    }
    EmployeeRecord e;
    e.id = -1;
    return e;
}

//void add_record() method
void EmployeeDatabase::add_record(){
  EmployeeRecord e;

  cout<<"\nAdding new record \n";
  cout<<"\nEnter employee ID : ";
  cin>>e.id;

  if((search_record_byID(e.id)).id != -1){
    cout<<"\nRecord already exist !";
    return;
  }
  cout<<"\nEnter employee name : ";
  cin>>e.name;

  cout<<"\nEnter employee designation : ";
  cin>>e.designation;

  cout<<"\nEnter employee salary : ";
  cin>>e.salary;

  e.status = true;

  //add this object to vector
  db.push_back(e);
}

//method to delete record from db
void EmployeeDatabase::delete_record(int id){
  for(int i = 0 ; i < db.size(); i++)
    if(db[i].id == id)
    {
      db[i].status = false;
    }
}

void EmployeeDatabase::display_record(EmployeeRecord e){

  if(e.id == -1)
    return;

  cout<<"\nEmployee ID : "<<e.id;
  cout<<"\nEmployee name : "<<e.name;
  cout<<"\nEmployee designation : "<<e.designation;
  cout<<"\nEmployee salary : "<<e.salary;
}

void EmployeeDatabase::display_all(){
  cout<<"\nAll records present in file... \n";

  for(int i = 0 ; i < db.size(); i++)
    if(db[i].status == true)
      display_record(db[i]);
}


int menu(){
  cout<<"\n\n\nEmployee Database \n1.add record\n2. delete record \n3.display all records\n4.search by number\n5.search by name\nChoose option : ";
  int opt;
  cin>>opt;

  return opt;
}
int main(){
  EmployeeDatabase ed;
  int opt;
  int data;
  string nm;

  while(1){
      system("clear");
      opt = menu();

      switch(opt){
        case 1:
          ed.add_record();
          break;
        case 2:
              cout<<"\nEnter employee ID : ";
              cin>>data;
              ed.delete_record(data);
              break;

        case 3:
          ed.display_all();
          break;

        case 4:
          cout<<"\nEnter employee ID : ";
          cin>>data;
          ed.display_record(ed.search_record_byID(data));
          break;
        case 5:
          cout<<"\nEnter employee name : ";
          cin>>nm;
          ed.display_record(ed.search_record_byName(nm));
          break;
      }
      getchar();
      getchar();
  }

  return 0;
}
