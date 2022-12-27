// Problem LInk :- https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/


class Solution {
public:

    struct TrieNode{
        TrieNode* left;
        TrieNode* right;
    };

    void insert(TrieNode* cur, int n){
        for(int i=31; i>=0; i--){
            int b = (n>>i)&1;
            if(b){
                if(!cur -> right)
                    cur -> right = new TrieNode();
                cur = cur -> right;
            }else{
                if(!cur -> left)
                    cur -> left = new TrieNode();
                cur = cur -> left;
            }
        }
    }
    int search(TrieNode* head, vector<int>& nums){
        int max = INT_MIN;
        int n = nums.size();
        for(int i=0; i<n; i++){
            TrieNode* temp = head;
            int cur = 0;
            for(int j=31; j>=0; j--){
                int b = (nums[i]>>j)&1;
                if(b){
                    if(temp->left){
                        cur += pow(2,j);
                        temp = temp->left;
                    }else{
                        temp = temp->right;
                    }
                }else{
                    if(temp->right){
                        cur += pow(2,j);
                        temp = temp->right;
                    }else{
                        temp = temp->left;
                    }
                }
            }
            if(max<cur) max = cur;
        }
        return max;
    }

    int findMaximumXOR(vector<int>& nums) {
        TrieNode* head = new TrieNode();
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            insert(head,nums[i]);
        }
        int ans = search(head,nums);

        if(ans == INT_MIN){
            return 0;
        }

        return ans;
    }
};