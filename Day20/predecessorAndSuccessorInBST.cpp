// Problem Link :- https://www.codingninjas.com/codestudio/problems/893049 


int successor(BinaryTreeNode<int>* root, int key){
    int ans=-1;
    
    while(root!=NULL){
        if(key>=root->data){
            root=root->right;
        }else{
            ans=root->data;
            root=root->left;
        }
    }
    return ans;
}

int predecessor(BinaryTreeNode<int>* root, int key){
    
    int ans=-1;
    
    while(root!=NULL){
        if(key>root->data){
            ans=root->data;
            root=root->right;
        }else{
            root=root->left;
        }
    }
    
    return ans;
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int b=predecessor(root, key);
    int a=successor(root, key);

    
    return {b, a};
}
