// Problem LInk :- https://www.codingninjas.com/codestudio/problems/920438


void solve(TreeNode<int>* root, int &k, int& ans){
    if(!root)return ;
    solve(root->right, k, ans);
    k--;
    if(k==0){
        ans=root->data;
        return ;
    }
    solve(root->left, k, ans);
}


int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int ans = -1;
    solve(root, k, ans);
    return ans;
}