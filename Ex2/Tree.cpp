#include <iostream>
#include "Tree.hpp"
using namespace std;
using namespace ariel;

    Node* t;

    void Tree::insert(int x){
    Node* temp = fun::insert(x,t);
     }

////// private methods ///////
        Node* fun::insert(int x, Node* t){
            if(t == NULL)
        {
            t = new Node(x);
            cout << t->data;
            return t;
        }
        if(t->data == x){
            /// throw exeption
        }
        else if(x < t->data)
            t->left = fun::insert(x, t->left);

        else if(x > t->data)
            t->right = fun::insert(x, t->right);
    
        return t;
        }



int main(){
    Tree t;

    t.insert(5);
    t.insert(3);  
    t.insert(8);

    return 0;
}