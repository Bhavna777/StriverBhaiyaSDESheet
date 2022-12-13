// Problem Link :- https://www.codingninjas.com/codestudio/problems/stack-implementation-using-array_3210209 


#include <bits/stdc++.h> 
// Stack class.
class Stack {
public:
    int *arr,size,topo;
    Stack(int capacity) {
        arr=new int[capacity];
        size=capacity;
        topo=-1;
    }
    void push(int num) {
        if(topo==size-1) {}
        else {
            arr[++topo]=num;       
        }
    }
    int pop() {
        if(topo!=-1){
            int ans=arr[topo];
            topo--;
            return ans;
        }
        else return -1; 
    }

    int top() {
        if(topo!=-1)
            return arr[topo];
        else return -1;
    }
    int isEmpty() {
        if(topo==-1) return 1;
        else return 0;
    }
    int isFull() {
        if(topo==size-1) return 1;
        else return 0;
    }
    
};