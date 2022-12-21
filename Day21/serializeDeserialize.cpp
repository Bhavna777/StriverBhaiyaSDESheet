// Problem Link :- https://leetcode.com/problems/serialize-and-deserialize-binary-tree/ 


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL){
            return "";
        }
        
        queue<TreeNode*> q;
        string s ="";

        q.push(root);

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if(curr == NULL){
                s.append("#,");
            }else{
                s.append(to_string(curr->val)+',');
            }

            if(curr != NULL){
                q.push(curr->left);
                q.push(curr->right);            
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0){
            return NULL; 
        }

        stringstream s(data);
        string str; 
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q; 
        q.push(root); 
        while(!q.empty()) {
            TreeNode *node = q.front(); 
            q.pop(); 
            
            getline(s, str, ',');
            if(str == "#") {
                node->left = NULL; 
            }else{
                TreeNode* left = new TreeNode(stoi(str)); 
                node->left = left; 
                q.push(left); 
            }
            
            getline(s, str, ',');
            if(str == "#") {
                node->right = NULL; 
            }else {
                TreeNode* right = new TreeNode(stoi(str)); 
                node->right = right;
                q.push(right); 
            }
        }
        return root; 
    }
};