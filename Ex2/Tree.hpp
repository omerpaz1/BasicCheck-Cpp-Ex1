#include <iostream>
using namespace std;

    struct Node
    {
        int data;
        Node* left;
        Node* right;
    };


namespace ariel{

    class Tree{
        public:
        Tree();
        void insert(int);
        void disp();

    };
}
namespace fun{

    Node* insert(int,Node*);
    void display(Node*,int);

}