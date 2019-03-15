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
	~Tree();
	void insert(int);
	void disp();
	int parent (int x);
	int right(int x);
	int left(int x);
	int size();
	int root_return();
	bool contains(int x);
	bool remove(int x);
	};
}
namespace fun{

	Node* insert(int,Node*);
	void display(Node*,int);
	Node* parent(Node* root, int n);
	int right(int x ,Node* root);
	int left(int x ,Node* root);
	int size(Node* root);
	Node* find(Node* t, int x);
	Node* remove(int x, Node* t);
	Node* makeEmpty(Node*);
    Node* findMin(Node* t);




}