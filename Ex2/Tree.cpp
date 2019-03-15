#include <iostream>
#include "Tree.hpp"
#include <iomanip>      // std::setw

using namespace std;
using namespace ariel;
    Node* root;


                                            // constractor //
    Tree::Tree()
    {
    root = NULL;
    }
                                            // distractor //   
    Tree::~Tree()
    {
        root = fun::makeEmpty(root);
    }
                                        



                                        ////// public methods ///////

 	void Tree::insert(int x){
		root = fun::insert(x,root);
	}
	void Tree::disp() { 
		fun::display(root, 10);
	}
	int Tree::parent (int x){
		Node* temp =fun::parent(root,x);
		if (temp==NULL) {
			cout <<"No Parent found"<<endl;
			return -1;
		}
		else return temp->data;
	}
	int Tree::left(int x){
		return fun::left(x,root);
	}

	int Tree::right(int x){
		return fun::right(x,root);
	}
	int Tree::size(){
		return fun::size(root);
	}

	int Tree::root_return(){
		return root->data;
	}

	bool Tree::contains(int x)
	{
		Node* temp = fun::find(root, x);
		if(temp==NULL)return false;
		else 
			return true ;
	}

	bool Tree::remove(int x)
	{
		Node* temp = fun::remove(x, root);
		if(temp == NULL) return false;
		else return true;
	}

                                        ////// end public methods ///////


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

// empty the tree //
 Node* fun::makeEmpty(Node* t)
    {
        if(t == NULL)
            return NULL;
        {
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


Node* fun::parent(Node* root, int n) {
	if (root == NULL)
		return NULL;
	else
		if ( (root->left!=NULL && root->left->data == n) || (root->right!=NULL) && (root->right->data == n)){
			return root;
		}
		else {
			Node* result= fun::parent(root->left, n);
			if (result!=NULL){
				return result;
			}
			else{
				return fun::parent(root->right, n);
			}
		}

}
int fun::left(int x ,Node* root){

    if(x == root->data){
       if(root->left == NULL){
           cout << "No Left Child for"<< x << endl;
           return -1;
       }
           else {
           return root->left->data;
         }
    }
    if(x < root->data){
        fun::left(x,root->left);
    }
    else if(x > root->data){
        fun::left(x,root->right);
    }
}

int fun::right(int x ,Node* root){

    if(x == root->data){
       if(root->right == NULL){
           cout << "No Right Child for"<< x << endl;
           return -1;
       }
           else {
           return root->right->data;
         }
    }
    if(x < root->data){
        fun::right(x,root->left);
    }
    else if(x > root->data){
        fun::right(x,root->right);
    }
}

int fun::size(Node* root)  
{  
	if (root == NULL)  
		return 0;  
	else
		return(fun::size(root->left) + 1 + fun::size(root->right));  
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


int main(){
    Tree t;

    t.insert(5);
    t.insert(3);  
    t.insert(8);
    t.insert(4);
    t.insert(2);


    t.disp();
    t.size();
    t.remove(3);
    t.disp();
    cout <<"left of 4 is: " << t.left(4)<<endl;
    cout <<"size is: " << t.size()<<endl;
    cout <<"right of 4 is: " << t.right(4)<<endl;


    return 0;
}