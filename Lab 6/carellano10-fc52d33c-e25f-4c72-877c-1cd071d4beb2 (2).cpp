#include<iostream>
#include<string>
#include<sstream>
using namespace std;

struct Node {
   int key;
   Node *left;
   Node *right;
   Node *p;
};

class BST {
public:
   BST();
   void Print(int num);
   void inorder(Node *n);
   void preOrder(Node *n);
   void postOrder(Node *n);
   void insert(int insertNum);
   void deleteT(int del);
   void transplant(Node *a, Node *b);
   Node* root;
   Node* treeMin(Node *n);
   Node* search(int n);
   Node* treeMax(Node *n);


};


BST::BST() {
   root = NULL;
}


void BST::insert(int insertNum) {
   Node* y = NULL;       
   Node* x = root;       
   Node* z = new Node();
   z->key = insertNum;
   while(x != NULL) {
       y = x;
       if (x->key > insertNum)
           x = x->left;
       else
           x = x->right;
   }
   z->p = y;
   if (y == NULL)
       root = z;
   else if (insertNum < y->key)
       y->left = z;
   else
       y->right = z;
}


void BST::deleteT(int del) {
   Node* x = search(del);
   Node* y;
   if (x->left == NULL)
       transplant(x, x->right);
   else if (x->right == NULL)
       transplant(x, x->left);
   else {
       y = treeMin(x->right);
       if (y->p != x) {
           transplant(y, y->right);
           y->right = x->right;
           y->right->p = y;
       }
       transplant(x,y);
       y->left = x->left;
       y->left->p = y;
   }
}



void BST::transplant(Node *u, Node *v) {
   if (u->p == NULL)
       root = v;
   else if (u == u->p->left)
       u->p->left = v;
   else
       u->p->right = v;
   if (v != NULL)
       v->p = u->p;
}
Node* BST::treeMin(Node *x) {
   while (x->left != NULL){
       x = x->left;
   }
   return x;
}



Node *BST::treeMax(Node *x) {
   while (x-> right != NULL){
       x = x-> right;
     
   }
   return x;
}



Node *BST::search(int k) {
   Node* x = root;
   while (x != NULL & k != x->key) {
       if (k < x->key){
           x = x->left;
       }
       else{
           x = x->right;
       }
   }
   return x;
}



void BST::preOrder(Node *t) {
   if (t != NULL) {
       cout << t-> key << endl;
       preOrder(t -> left);
       preOrder(t -> right);
   }
}



void BST::postOrder(Node *w) {
   if (w != NULL) {
       postOrder(w -> left);
       postOrder(w -> right);
       cout << w->key << endl;
   }
}



void BST::inorder(Node *x) {
   if (x != NULL) {
       inorder(x -> left);
       cout << x -> key << endl;
       inorder (x -> right);
   }
}



void BST::Print(int num) {
   if(num == 1){
       inorder(root);
       }


   else if(num == 2){
       preOrder(root);
       
       }
       
   else if(num == 3){
       postOrder(root);
       
       }
}





int main(int argc,char **argv) {
   BST BST;
 // Using a fixed size buffer for reading content is not always safe,
 // but ok here because we know how our input has to be:
   char line[100];
 // Main loop
   while (std::cin.getline(line,100)) {


       string str(line);
       if (str.size() == 0) continue;
       if (str[0] == 'e') return 1;

       
   // Use cerr if you want to always print to the console, because cout
   // will be redirected to the output file when calling the Grade script:
   // cerr<<line<<endl;
       if (str[0] == 'o') {
           if (str.substr(0,3) == "oin"){
               BST.Print(1);
             
               }
           else if (str.substr(0,4) == "opre"){
               BST.Print(2);
             
               }
           else if (str.substr(0,5) == "opost"){
               BST.Print(3);
           }
       }
       else {
 
          
           int key;
           stringstream convert_stm(str.substr(1,str.size()-1));
           if (!(convert_stm >> key))
               key = -1;
           if (str.substr(0,1) == "i"){
               BST.insert(key);
               }
 
           else if (str.substr(0,1) == "d"){
               BST.deleteT(key);
              
              
              
              
               }
       }
   }
   return 1;
}


