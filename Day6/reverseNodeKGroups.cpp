// Problem Link :- https://leetcode.com/problems/reverse-nodes-in-k-group 


int getLength(ListNode* head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head -> next;
    }

    return count;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == NULL || head -> next == NULL){
        return head;
    }

    int length = getLength(head);

    ListNode* temp = new ListNode(0);

    temp -> next = head;

    ListNode* pre = temp;
    ListNode* curr;
    ListNode* nex;

    while(length >= k){
        curr = pre -> next;
        nex = curr -> next;
        for(int i=1; i<k; i++) {
            curr -> next = nex -> next;
            nex -> next = pre -> next;
            pre -> next = nex;
            nex = curr -> next;
        }
        pre = curr;
        length -= k;

    }

    return temp -> next;
}