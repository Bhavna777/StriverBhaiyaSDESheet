// Problem Link :- https://leetcode.com/problems/delete-node-in-a-linked-list/ 

void deleteNode(ListNode* node) {
    node -> val = node -> next -> val;
    node -> next = node -> next -> next;
    return;
}