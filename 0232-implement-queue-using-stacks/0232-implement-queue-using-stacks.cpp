class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s1.empty()){
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
        else if(s2.empty()){
            while(!s1.empty()){
                int k=s1.top();
                s1.pop();
                s2.push(k);
            }
            s2.push(x);
            while(!s2.empty()){
                int k=s2.top();
                s2.pop();
                s1.push(k);
            }
        }
    }
    
    int pop() {
        int k;
        if(s1.empty()){
            k=s2.top();
            s2.pop();
        }
        else{
            k=s1.top();
            s1.pop();
        }
        return k;
    }
    
    int peek() {
        if(s1.empty())
        return s2.top();
        else
        return s1.top();
    }
    
    bool empty() {
        return s1.empty()&&s2.empty();
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