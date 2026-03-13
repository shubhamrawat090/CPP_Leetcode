class MyStack {
    queue<int> q;
public:
    MyStack() {
        this->q = {};
    }
    
    void push(int x) {
        // push in queue
        // pop and push back n-1 elems in the same queue
        q.push(x);
        int n = q.size();
        for(int i=0; i<n-1; i++) {
            int top = q.front();
            q.pop();
            q.push(top);
        }        
    }
    
    int pop() {
        if(q.empty()) return -1;
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        if(q.empty()) return -1;
        int top = q.front();
        return top;
    }
    
    bool empty() {
        return q.empty();        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */