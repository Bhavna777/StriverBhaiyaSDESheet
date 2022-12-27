// Problem LInk :- https://leetcode.com/problems/maximum-xor-with-an-element-from-array/


class Solution {
public:

    struct Node {
        Node* zeroBit = NULL;
        Node* oneBit = NULL;
    };
    Node* root = new Node();
  
    void insert(const int& num) {
        Node* ptr = root;
        for (int i = 31; i >= 0; i--) {
            if ((num >> i) & 1) {
                if (!ptr->oneBit) ptr->oneBit = new Node();
                ptr = ptr->oneBit;
            } else {
                if (!ptr->zeroBit) ptr->zeroBit = new Node();
                ptr = ptr->zeroBit;
            }
        }
    }
  
    int getMaxXOR(const int& num) {
        if (root->zeroBit == NULL && root->oneBit == NULL){
            return -1;
        }
        Node* ptr = root;
        int temp = 0;
        for (int i = 31; i >= 0; i--) {
            if ((num >> i) & 1) {
                if (ptr->zeroBit) {
                    temp += pow(2,i);
                    ptr = ptr->zeroBit;
                } else {
                    ptr = ptr->oneBit;
                }
            } else {
                if (ptr->oneBit) {
                    temp += pow(2,i);
                    ptr = ptr->oneBit;
                } else {
                    ptr = ptr->zeroBit;
                }
            }
        }
        return temp;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> q;
        for (int i = 0; i < queries.size(); i++) {
            auto v = queries[i];
            q.push_back({v[1], v[0], i});
        }
        sort(q.begin(), q.end());
        sort(nums.begin(), nums.end());
        
        int j = 0;
        vector<int> ans(queries.size());
        
        for (const auto& p : q) {
            int x = p[1];
            int threshold = p[0];
            while (j < nums.size() && nums[j] <= threshold) {
                insert(nums[j]);
                j++;
            }
            ans[p[2]] = getMaxXOR(x);
        }
        return ans;
    }
};