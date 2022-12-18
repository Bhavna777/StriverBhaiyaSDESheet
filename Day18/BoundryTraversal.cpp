// Problem Link :- https://www.codingninjas.com/codestudio/problems/boundary-traversal_790725 



void traverseLeft(TreeNode<int>* root,vector<int>& ans){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        return;
    }
    ans.push_back(root->data);
    if(root->left){
        traverseLeft(root->left,ans);
    }else{
        traverseLeft(root->right,ans);
    }
}

void getLeaf(TreeNode<int>* root,vector<int>& ans){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }
    getLeaf(root->left,ans);
    getLeaf(root->right,ans);
}

void traverseRight(TreeNode<int>* root,vector<int>& ans){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        return;
    }
    if(root->right){
        traverseRight(root->right,ans);
    }else{
        traverseRight(root->left,ans);
    }
    ans.push_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    ans.push_back(root->data);
    traverseLeft(root->left,ans);
    getLeaf(root->left,ans);
    getLeaf(root->right,ans);
    traverseRight(root->right,ans);
    
    return ans;
}