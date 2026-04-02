class MinStack {
public:
    stack<int> s;
    stack<int> st;
    MinStack() {
    }
    
    void push(int val) {
        s.push(val);
        if(st.empty() || val < st.top()){
            st.push(val);
        }else{
            st.push(st.top());
        }
    }
    
    void pop() {
        s.pop();
        st.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return st.top();
    }
};
