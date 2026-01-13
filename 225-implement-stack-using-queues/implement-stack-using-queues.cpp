class MyStack {
    queue<int> q;
public:
    MyStack() {}
    
    void push(int x) {
        // add target elem in queue
        // remove and add back first n-1 elements back in the same queue
        q.push(x);
        int size = q.size();
        for(int i=0; i<size-1; i++) {
            int elem = q.front();
            q.pop();
            q.push(elem);
        }
    }
    
    int pop() {
        int elem = q.front();
        q.pop();
        return elem;
    }
    
    int top() {
        return q.front();
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