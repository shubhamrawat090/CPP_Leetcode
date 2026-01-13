class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s1.empty()) {
            s1.push(x);
        } else {
            // move all from s1->s2
            while(!s1.empty()) {
                int elem = s1.top();
                s1.pop();
                s2.push(elem);
            }
            // push to s1
            s1.push(x);
            // move all from s2->s1
            while(!s2.empty()) {
                int elem = s2.top();
                s2.pop();
                s1.push(elem);
            }
        }       
    }
    
    int pop() {
        if(s1.empty()) return -1; // nothing present
        int elem = s1.top();
        s1.pop();
        return elem;
    }
    
    int peek() {
        if(s1.empty()) return -1; // nothing present
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */