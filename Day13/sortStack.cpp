// Problem Link :- https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275 


#include <bits/stdc++.h> 
void sortedInsert(stack<int> &stack, int num){
    if(stack.empty() || (!stack.empty() && stack.top() < num)){
        stack.push(num);
        return ;
    }
    
    int element = stack.top();
    stack.pop();
    
    sortedInsert(stack, num);
    
    stack.push(element);
}

void sortStack(stack<int> &stack)
{
	if(stack.empty()){
        return ;
    }
    
    int num = stack.top();
    stack.pop();
    
    sortStack(stack);
    
    sortedInsert(stack, num);
}