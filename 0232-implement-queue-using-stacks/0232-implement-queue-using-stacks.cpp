class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s2.empty()){
            int k=s2.top();
            s2.pop();
            s1.push(k);
        }
        s1.push(x);
        while(!s1.empty()){
            int k=s1.top();
            s1.pop();
            s2.push(k);
        }
    }
    
    int pop() {
        int k=s2.top();
        s2.pop();
        return k;
    }
    
    int peek() {
        return s2.top();
    }
    
    bool empty() {
        return s2.empty();
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