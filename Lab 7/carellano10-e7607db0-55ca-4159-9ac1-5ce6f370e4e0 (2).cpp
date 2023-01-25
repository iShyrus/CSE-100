#include<iostream> 
#include <list> 
using namespace std; 
  

class Hash{ 
list<int> *L;
int mod; 


public: 
int hashFunction(int key){ 
    return (key % mod);
    }
void deleteKey(int key);
void print();
void search(int key);
void insertion(int key);
Hash(int construct);
};


Hash::Hash(int key){ 
this->mod = key; 
L = new list<int>[mod]; 
} 




void Hash::insertion(int key){
    int i=0;
    int j=key%mod;
   if(mod!=0){
    L[j].push_front(key);
    }
} 



  
void Hash::deleteKey(int key){

list <int> :: iterator i; 
int index = hashFunction(key); 

for (i = L[index].begin(); i != L[index].end(); i++) { 
    if (*i == key) {
            L[index].erase(i); 
            cout<<key<<":DELETED;"<<endl;
        break; 
        }
    }
    if (i==L[index].end()){
    cout<<key<< ":DELETE_FAILED;"<<endl;
    }


}





 
void Hash::print(){
list <int> :: iterator j; 

for(int i = 0; i <mod; i++){
    cout << i <<":";
    for(j = L[i].begin(); j!= L[i].end(); j++){
        
        if (j==L[i].begin()){
        cout<<*j<<"->";}
        else if(j!=L[i].end()){
            cout<<*j<<"->";
        }
    }
    cout<<";"<<endl;
    }

}

void Hash::search(int key){
    int index = hashFunction(key);
    list<int>::iterator i;
    int count = 0;


    for( i = L[index].begin(); i!= L[index].end(); i++){
        if(*i==key){
            cout<<key<<":FOUND_AT"<<index<<","<<count<<";"<<endl;
            break;
        }
        count++;
    }

    if (i== L[index].end()){
    cout<<key<<":NOT_FOUND;"<<endl;
    }
}




int main(int argc, char const *argv[]) {

  int number =  0;
  bool repeat = true;
  int hashSize;

  string input = "";
  cin >> hashSize;
  Hash h(hashSize); 


  do{
      number = 0;
      cin >> input;
      //Create integer if required by function
      if (input[0] != 'o' || input[0] != 'e'){
        for (int i = 1; i < input.size(); i++){
          int digit = input[i] - '0';
          number = 10 * number + digit;
        }
      }

      if(input[0] == 'i'){
 
          h.insertion(number);
         

      }else if(input[0] == 'd'){

        h.deleteKey(number);

      }else if(input[0] == 's'){

         h.search(number);

      }else if(input[0] == 'o'){

            h.print();

      }else if(input[0] == 'e'){
        repeat = false;
      }
      else{
        cout<<"Wrong Input"<<endl;
      }
      
  }while(repeat);

  return 0;
}