class MinStack {
public:
    stack<int> pq;
    stack<int> s;
    MinStack() {
    }
    
    void push(int val) {
        pq.push(val);
        if(s.empty() || val < s.top()){
            s.push(val);
        }
        else{
            s.push(s.top());
        }
    }
    
    void pop() {
        pq.pop();
        s.pop();
    }
    
    int top() {
        return pq.top();
    }
    
    int getMin() {
        return s.top();
    }
};
