#include <iostream>
#include "Node.hpp"
using namespace std;
#define COUNT 10

namespace ariel{

    class Tree{
        public:
        //Tree();
        void insert(int);
        void printTree();



//////////// Private Methods \\\\\\\\\\\

    private:
    void printTree(Node* t){
    if(!t) return;

    if(t->left)  printTree(t->left);

    printf("Cle = %d\n", t->data);

    if(t->right) printTree(t->right);
    }

    };

}