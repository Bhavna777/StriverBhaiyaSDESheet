// Problem Link :- https://leetcode.com/problems/linked-list-cycle-ii/ 


ListNode *detectCycle(ListNode *head) {
    if(head == NULL){
        return NULL;
    }

    ListNode* temp = head;
    unordered_map<ListNode*, bool>visited;

    while(temp != NULL){
        if(visited[temp] == true){
            return temp;
        }

        visited[temp] = true;
        temp = temp -> next;
    }

    return NULL;
}