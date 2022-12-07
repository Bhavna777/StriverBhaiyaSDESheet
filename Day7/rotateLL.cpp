// Problem Link :- https://leetcode.com/problems/rotate-list 


ListNode* rotateRight(ListNode* head, int k) {

    ListNode* temp = head;
    int length = 1;
    while(temp->next != NULL) {
        ++length;
        temp = temp->next;
    }
    temp -> next = head;


    if(k == 0 || head == NULL || head -> next == NULL){
        return head;
    } 

    k = k % length;

    int end = length - k;

    while(end != 0){
        temp = temp->next;
        end--;
    }
    

    head = temp->next;
    temp->next = NULL;
        
    return head;
}