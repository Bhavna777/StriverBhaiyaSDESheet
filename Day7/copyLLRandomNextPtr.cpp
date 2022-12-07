


Node* copyRandomList(Node* head) {

    if(head == NULL){
        return head;
    }

    unordered_map<Node*, Node*>mp;
    Node* temp = head;
    Node* newHead = new Node(temp -> val);

    mp[temp] = newHead;

    while (temp->next != NULL) {
        newHead->next = new Node(temp->next->val);
        temp = temp->next;
        newHead = newHead->next;
        mp[temp] = newHead;
    }
    temp = head;

    while (temp != NULL) {
        mp[temp] -> random = mp[temp -> random];
        temp = temp -> next;
    }

    return mp[head];
}