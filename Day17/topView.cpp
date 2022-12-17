// Problem LInk :- https://www.codingninjas.com/codestudio/problems/799401 



vector<int> getTopView(TreeNode<int> *root) {
   vector<int> ans;
   queue<pair<TreeNode<int> *,int>> q;
   map<int,int> mp;
   if(!root) return ans;
   q.push({root,0});
   
   while(!q.empty()){
       TreeNode<int> *node=q.front().first;
       int line = q.front().second;
       if(mp.find(line)==mp.end())
       mp[line]=node->val;
       if(node->left){
           q.push({node->left,line-1});
       }
       if(node->right){
           q.push({node->right,line+1});
       }
       q.pop();
   }
   for(auto it : mp) {
       ans.push_back(it.second); 
   }
   return ans;
}