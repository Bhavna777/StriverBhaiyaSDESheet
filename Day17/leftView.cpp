// Problem LInk :- https://www.codingninjas.com/codestudio/problems/920519 




void solve(TreeNode<int> *root, int level, vector<int> &ans)
    {
        if(root==NULL){
            return ;
        } 
        if(ans.size()==level){
            ans.push_back(root->data);
        } 
        solve(root->left, level+1, ans);
        solve(root->right, level+1, ans);
}


vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    solve(root, 0, ans);
    return ans;
}