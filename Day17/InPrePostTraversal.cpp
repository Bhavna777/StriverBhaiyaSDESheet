// Problem LInk :- https://www.codingninjas.com/codestudio/problems/981269 



void inorder(BinaryTreeNode<int>* root, vector<int>&inOrder){
    if(root == NULL){
        return ;
    }

    inorder(root -> left, inOrder);
    inOrder.push_back(root -> data);
    inorder(root -> right, inOrder);
}

void preorder(BinaryTreeNode<int>* root, vector<int>&preOrder){
    if(root == NULL){
        return ;
    }

    preOrder.push_back(root -> data);
    preorder(root -> left, preOrder);
    preorder(root -> right, preOrder);
}

void postorder(BinaryTreeNode<int>* root, vector<int>&postOrder){
    if(root == NULL){
        return ;
    }

    postorder(root -> left, postOrder);
    postorder(root -> right, postOrder);
    postOrder.push_back(root -> data);
}


vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>>ans;
    vector<int>inOrder;
    vector<int>preOrder;
    vector<int>postOrder;
    
    inorder(root, inOrder);
    ans.push_back(inOrder);
    preorder(root, preOrder);
    ans.push_back(preOrder);
    postorder(root, postOrder);
    ans.push_back(postOrder);
    
    
    return ans;
}