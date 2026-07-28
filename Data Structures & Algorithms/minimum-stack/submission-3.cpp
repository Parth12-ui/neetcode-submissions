class MinStack {

private:
    stack<pair<int, int>> s;
    int min;
public:
    MinStack() {}
    
    void push(int val) {
        if (s.empty()) min = val;

        if (val < min) min = val;
        s.emplace(val, min);
    }
    
    void pop() {
        s.pop();
        if (!s.empty()) min = s.top().second;
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};
