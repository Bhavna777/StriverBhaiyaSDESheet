// Problem Link :- https://leetcode.com/problems/clone-graph/description/


class Solution {
public:

    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        if (mp.find(node) == mp.end()) {
            mp[node] = new Node(node -> val, {});
            for (Node* neighbor : node -> neighbors) {
                mp[node] -> neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return mp[node];
    }
};