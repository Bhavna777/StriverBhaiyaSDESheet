// Problem Link :- https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/



class Solution {
public:

    void traverse(TreeNode* node, int x, int y,  map<int, multiset<pair<int, int>>>& mp){
        if(!node) return;
        mp[x].insert({y, node->val});
        traverse(node->left, x-1, y+1, mp);
        traverse(node->right, x+1, y+1, mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, multiset<pair<int, int>>> mp; // [x][y, val]
        traverse(root, 0, 0, mp);
        vector<vector<int>> ans;
        for(auto& [x, st] : mp)
        {
            ans.push_back({});
            for(auto& [y, val] : st) ans.back().push_back(val);
        }
        return ans;
    }
};