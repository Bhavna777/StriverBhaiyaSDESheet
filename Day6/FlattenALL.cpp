Node* mergeBothLists(Node* a, Node* b) {
    Node *temp = new Node(0);
    Node *ans = temp; 
    
    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            temp -> bottom = a; 
            temp = temp -> bottom; 
            a = a -> bottom; 
        }else {
            temp -> bottom = b;
            temp = temp->bottom; 
            b = b -> bottom; 
        }
    }
    
    if(a){
        temp -> bottom = a; 
    }else{
        temp -> bottom = b; 
    } 
    
    return ans -> bottom; 
}
    
Node *flatten(Node *root)
{
    if (root == NULL || root->next == NULL){
       return root; 
    }
    
    root->next = flatten(root->next); 
    
    root = mergeBothLists(root, root->next); 
    
    return root;
}