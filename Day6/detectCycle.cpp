// Problem Link :- https://leetcode.com/problems/linked-list-cycle 


bool hasCycle(ListNode *head) {
    if(head == NULL){
        return false;
    }

    ListNode* temp = head;
    unordered_map<ListNode*, bool>visited;

    while(temp != NULL){
        if(visited[temp] == true){
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;
    }

    return false;
}