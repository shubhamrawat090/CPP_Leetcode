class MinStack {
    stack<int> st;
    stack<int> minSt;

public:
    MinStack() {
        st = {};
        minSt = {};
        minSt.push(INT_MAX);
    }

    void push(int val) {
        int minVal = min(minSt.top(), val);
        minSt.push(minVal);
        st.push(val);
    }

    void pop() {
        minSt.pop();
        st.pop();
    }

    int top() {
        if (st.empty())
            return -1;
        int top = st.top();
        return top;
    }

    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */