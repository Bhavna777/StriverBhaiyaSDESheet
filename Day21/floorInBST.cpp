// Problem Link :- https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457


int floorInBST(TreeNode<int> * root, int X)
{    
    int ans;
    while(root){
        if(X > root->val){
            ans = root->val;
            root = root->right;
        }
        else if(X < root->val){
            root = root->left;
        }
        else{
            return X;
        }
    }
    return ans;
}