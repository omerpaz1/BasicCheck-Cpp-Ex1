#include <iostream>
#include "Tree.hpp"
#include <iomanip>      // std::setw

using namespace std;
using namespace ariel;
    //Node* root;


                                            // constractor //
    Tree::Tree()
    {
    Tree::myroot = NULL;
    }
                                            // distractor //   
    Tree::~Tree()
    {
        myroot = fun::makeEmpty(myroot);
    }
                                        
                                        ////// public methods ///////

 	void Tree::insert(int x){
		myroot = fun::insert(x,myroot);
	}
	void Tree::print() { 
		fun::display(myroot, 10);
	}
	int Tree::parent (int x){
		Node* temp =fun::parent(myroot,x);
		if (temp==NULL) {
			cout <<"No Parent found"<<endl;
			return -1;
		}
		else return temp->data;
	}
	int Tree::left(int x){
		return fun::left(x,myroot);
	}

	int Tree::right(int x){
		return fun::right(x,myroot);
	}
	int Tree::size(){
		return fun::size(myroot);
	}

	int Tree::root(){
		return myroot->data;
	}

	bool Tree::contains(int x)
	{
		Node* temp = fun::find(myroot, x);
		if(temp==NULL)return false;
		else 
			return true ;
	}

	bool Tree::remove(int x)
	{
		Node* temp = fun::remove(x, myroot);
		if(temp == NULL) return false;
		else return true;
	}

                                        ////// end public methods ///////


                                        ////// private methods ///////

	// priting function that took from interent.									

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

// empty the tree //
 Node* fun::makeEmpty(Node* t)
    {
        if(t != NULL){
            fun::makeEmpty(t->left);
            fun::makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }
    Node* fun::remove(int x, Node* t)
{
	Node* temp;
	if(t == NULL)
		return NULL;
	else if(x < t->data)
		t->left = fun::remove(x, t->left);
		else if(x > t->data)
			t->right = fun::remove(x, t->right);
			else if(t->left && t->right)
			{
				temp = fun::findMin(t->right);
				t->data = temp->data;
				t->right = fun::remove(t->data, t->right);
			}
			else
			{
				temp = t;
				if(t->left == NULL)
					t = t->right;
					else if(t->right == NULL)
						t = t->left;
						delete temp;
			}

	return t;
}

Node* fun::findMin(Node* t)
{
	if(t == NULL)
		return NULL;
	else if(t->left == NULL)
		return t;
	else
		return fun::findMin(t->left);
}


Node* fun::insert(int x, Node* p){

	if(p == NULL){
		p = new Node;
		p->data = x;
		p->left = p->right = NULL;
	}
	if(p->data == x){
	throw invalid_argument("This numer is allready in the Tree");

	}
	else if(x < p->data){
		p->left = fun::insert(x, p->left);
	}
	if(x > p->data)
		p->right = fun::insert(x, p->right);

		return p;
}


Node* fun::parent(Node* myroot, int n) {
	if (myroot == NULL)
		return NULL;
	else
		if ( (myroot->left!=NULL && myroot->left->data == n) || (myroot->right!=NULL) && (myroot->right->data == n)){
			return myroot;
		}
		else {
			Node* result= fun::parent(myroot->left, n);
			if (result!=NULL){
				return result;
			}
			else{
				return fun::parent(myroot->right, n);
			}
		}

}
int fun::left(int x ,Node* myroot){

    if(x == myroot->data){
       if(myroot->left == NULL){
           cout << "No Left Child for"<< x << endl;
           return -1;
       }
           else {
           return myroot->left->data;
         }
    }
    if(x < myroot->data){
        fun::left(x,myroot->left);
    }
    else if(x > myroot->data){
        fun::left(x,myroot->right);
    }
}

int fun::right(int x ,Node* myroot){

    if(x == myroot->data){
       if(myroot->right == NULL){
           cout << "No Right Child for"<< x << endl;
           return -1;
       }
           else {
           return myroot->right->data;
         }
    }
    if(x < myroot->data){
        fun::right(x,myroot->left);
    }
    else if(x > myroot->data){
        fun::right(x,myroot->right);
    }
}

int fun::size(Node* myroot)  
{  
	if (myroot == NULL)  
		return 0;  
	else
		return(fun::size(myroot->left) + 1 + fun::size(myroot->right));  
}

Node* fun::find(Node* t, int x)
{
	if(t == NULL)
		return NULL;
	else if(x < t->data)
		return fun::find(t->left, x);
	else if(x > t->data)
		return fun::find(t->right, x);
	else
		return t;
}






                                        ////// end  private methods ///////

