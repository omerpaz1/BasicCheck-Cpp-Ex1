#include <iostream>
#include "Tree.hpp"
using namespace std;
using namespace ariel;

    Node* t;

    void Tree::insert(int x){
    Node* temp = insert(x,t);
    cout << temp->data;
     }

////// private methods ///////
        Node* insert(int x, Node* t){
            if(t == NULL)
        {
            t = new Node(x);
            return t;
        }
        if(t->data == x){
            /// throw exeption
        }
        else if(x < t->data)
            t->left = insert(x, t->left);
        else if(x > t->data)
            t->right = insert(x, t->right);
    
        return t;
        }



int main(){
    Tree t;

    t.insert(5);
    t.insert(3);  
    t.insert(8);


    
    return 0;
};