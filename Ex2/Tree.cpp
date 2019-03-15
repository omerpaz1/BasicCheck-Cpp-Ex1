#include <iostream>
#include "Tree.hpp"
#include <iomanip>      // std::setw

using namespace std;
using namespace ariel;



    Node* t;

    void Tree::insert(int x){
    t = fun::insert(x,t);
     }
    void Tree::disp() { 
    fun::display(t, 10);
    }

////// private methods ///////

    void fun::display(Node* p, int indent) {

    if (p != NULL) {
    if (p->right) {
      fun::display(p->right, indent + 4);
    }
    if (indent) {
      cout << setw(indent) << ' ';
    }
    if (p->right) cout << " /\n" << setw(indent) << ' ';
    cout << p->data << "\n ";
    if (p->left) {
      cout << setw(indent) << ' ' << " \\\n";
      fun::display(p->left, indent + 4);
    }
  }
}

// insert function 
        Node* fun::insert(int x, Node* t){

            if(t == NULL)
        {
            t = new Node;
            t->data = x;
            t->left = t->right = NULL;
        }

        else if(x < t->data){
            t->left = fun::insert(x, t->left);

        }

        if(x > t->data)
            t->right = fun::insert(x, t->right);
    
        return t;
        }

///////// end ////////////

int main(){
    Tree t;

    t.insert(5);
    t.insert(3);  
    t.insert(8);
    t.insert(4);
    t.insert(2);


    t.disp();

    return 0;
}