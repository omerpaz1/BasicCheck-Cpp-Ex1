#include <iostream>
#include "Tree.hpp"
#include <iomanip>      // std::setw

using namespace std;
using namespace ariel;

    Tree::Tree(){
    }

    Node* root;

    void Tree::insert(int x){
    root = fun::insert(x,root);
     }
    void Tree::disp() { 
    fun::display(root, 10);
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
        Node* fun::insert(int x, Node* p){

            if(p == NULL)
        {
            p = new Node;
            p->data = x;
            p->left = p->right = NULL;
        }

        else if(x < p->data){
            p->left = fun::insert(x, p->left);

        }

        if(x > p->data)
            p->right = fun::insert(x, p->right);
    
        return p;
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