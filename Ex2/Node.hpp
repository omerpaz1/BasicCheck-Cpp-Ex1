class Node  
{  
    public: 
    int data;  
    Node* left;
    Node* right;  
      
    /* Constructor that allocates a new node with the  
    given data and NULL left and right pointers. */
    Node(int data){ 
        this->data = data; 
        this->left = NULL; 
        this->right = NULL; 
    } 
}; 


  }