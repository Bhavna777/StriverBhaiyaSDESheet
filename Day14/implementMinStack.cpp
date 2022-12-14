// Problem Link :- https://leetcode.com/problems/min-stack/ 


class MinStack {
public:

    stack < pair < int, int >> s;

    MinStack() {
        
    }
    
    void push(int val) {
        int mini;
        
        if (s.empty()) {
            mini = val;
        } else {
            mini = min(s.top().second, val);
        }

        s.push({val,mini});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        int temp = s.top().first;
        return temp;
    }
    
    int getMin() {
        int temp = s.top().second;
        return temp;
    }
};

/**
 * Your Minstack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */