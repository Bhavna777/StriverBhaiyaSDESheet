// Problem Link :- https://leetcode.com/problems/palindrome-linked-list 


bool isPalindrome(ListNode* head) {
    vector<int>v;
    while(head != NULL){
        v.push_back(head -> val);
        head = head -> next;
    }

    int n = v.size();
    int start = 0;
    int end = n - 1;
    while(start <= end){
        if(v[start] != v[end]){
            return false;
        }
        start++;
        end--;
    }

    return true;
}