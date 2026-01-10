class MyStack {
    queue<int> q;

public:
    MyStack() {}

    void push(int x) {
        q.push(x);
        int sz = q.size();
        // rotate previous elements
        while (sz-- > 1) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (q.empty()) return -1;
        int elem = q.front();
        q.pop();
        return elem;
    }

    int top() {
        if (q.empty()) return -1;
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
 * int param_3 = obj->front();
 * bool param_4 = obj->empty();
 */