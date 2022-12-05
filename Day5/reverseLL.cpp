// Problem Link :- https://leetcode.com/problems/reverse-linked-list 

ListNode* reverseList(ListNode* head) {
    ListNode *temp = NULL;
    while (head != NULL) {
        ListNode *next = head->next;
        head->next = temp;
        temp = head;
        head = next;
    }
    return temp;
}