class StockSpanner {
private:
    stack<int> s;
    stack<int> temp;
public:
    StockSpanner() {}
    
    int next(int price) {
        int count = 1;
        while(!s.empty() && s.top() <= price){
            temp.push(s.top());
            s.pop();
            count++;
        }

        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }


        s.push(price);
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */