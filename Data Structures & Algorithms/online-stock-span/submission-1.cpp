class StockSpanner {
private:
    stack<int> s;
public:
    StockSpanner() {}
    
    int next(int price) {
        stack<int> temp;
        bool flag = true;
        int span = 1;
        while(!s.empty()){
            if (flag && s.top() <= price) span++;
            else if (s.top() > price) flag = false;
            
            temp.push(s.top());
            s.pop(); 
        }

        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }

        s.push(price);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */