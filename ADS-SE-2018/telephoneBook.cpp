#include<iostream>
#include<string.h>

using namespace std;


class record{
  public:
    string nm;
    string phno;
};

class phoneDB{
    record *rec;
    int n;

  public:

    phoneDB()
    {
      n = 26*26*26;
      rec = new record[n];

      //initiating the hash table
      for(int i = 0 ; i < n ; i++){
        rec->nm = "";
      }
    }


    int calculateIndex(string nm){
      int i1 =(int)nm[0], i2 =(int)nm[1], i3 =(int)nm[2];

      if(i1 >=65 && i1 <= 90)
        i1 -= 64; // getting index position in alphabetical order

      if(i1 >=97 && i1 <= 122)
          i1 -= 96; // getting index position in alphabetical order

      if(i2 >=65 && i2 <= 65)
          i2 -= 64; // getting index position in alphabetical order

      if(i2 >=97 && i2 <= 122)
        i2 -= 96; // getting index position in alphabetical order

      if(i3 >=65 && i3 <= 90)
        i3 -= 64; // getting index position in alphabetical order

      if(i3 >=97 && i3 <= 122)
        i3 -= 96; // getting index position in alphabetical order

      i1 = i1*26*26;
      i2 = i2*26;

      i3 = i1+i2+i3;

      return i3;
    }

    //method to add new record
    void addRecord(string nm, string phno){

      int ind = calculateIndex(nm);

      if(rec[ind].nm == ""){//record location free
        rec[ind].nm = nm;
        rec[ind].phno = phno;

        return;
      }

      //else find location through linear probing

      int limit = ind++;
      while(ind != limit){
        if(rec[ind].nm == ""){//record location free
          rec[ind].nm = nm;
          rec[ind].phno = phno;
          return;
        }
        ind = (ind+1) % n;
      }
      //else no empty location found
      cout<<"hash table full !";

      return;
    }

    //method to get record
    string getRecord(string nm){
      int ind = calculateIndex(nm);

      if(rec[ind].nm == nm){//record location free
        cout<<"\nRecord index : "<<ind;
        return rec[ind].phno;
      }

      //else find location through linear probing

      int limit = ind++;
      while(ind != limit){
        if(rec[ind].nm == nm){//record location found
          cout<<"\nRecord index : "<<ind;
          return rec[ind].phno;
        }
        ind = (ind+1) % n;

      }
      //record not found
      return "";
    }

    void delRecord(string nm){

      int ind = calculateIndex(nm);

      if(rec[ind].nm == nm){//record location free
        rec[ind].nm = "";
        cout<<"\nRecord index : "<<ind<<" successfily deleted !";
        return;
      }

      //else find location through linear probing

      int limit = ind++;
      while(ind != limit){
        if(rec[ind].nm == nm){//record location found
          rec[ind].nm = "";
          cout<<"\nRecord index : "<<ind<<" successflly deleted !";
          return;
        }
        ind = (ind+1) % n;
      }
      cout<<"\nRecord not found !";
      return;
    }
};


int menu(){
  cout<<"\n1.Add no. \n2. Display no. \n3.delete no. \n4.exit\nChoose option : ";
  int opt;
  cin>>opt;

  return opt;
}


int main(){
  int opt;
  string nm, phno;
  phoneDB ph;

  while(1){

    system("clear");
    int opt = menu();

    if(opt > 4)
      break;
    switch(opt){
      case 1:
        cout<<"\nEnter name : ";
        cin>>nm;
        cout<<"\nEnter ph no : ";
        cin>>phno;

        ph.addRecord(nm, phno);

        break;

      case 2:
        cout<<"\nEnter name : ";
        cin>>nm;

        phno = ph.getRecord(nm);
        if(phno == "")
          cout<<"\nRecord not found !";
        else
          cout<<"\nPhone number : "<<phno;

        break;

      case 3:
        cout<<"\nEnter name : ";
        cin>>nm;
        ph.delRecord(nm);
        break;

    }
    getchar();
    getchar();
  }
}
