class MyQueue {
private:
    stack<int> s;
public:
    MyQueue() {}
    
    void push(int x) {
        stack<int> temp;
        while(!s.empty()){
            int num = s.top();
            s.pop();
            temp.push(num);
        }

        temp.push(x);
        while(!temp.empty()){
            int num = temp.top();
            temp.pop();
            s.push(num);
        }
    }
    
    int pop() {
        int num = s.top();
        s.pop();
        return num;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
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