class FreqStack {
private:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> freqs;
    int maxFreq;
public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        freq[val]++;
        if (freq[val] > maxFreq) maxFreq = freq[val];

        freqs[freq[val]].push(val);
    }
    
    int pop() {
        int num = freqs[maxFreq].top();
        freqs[maxFreq].pop();

        freq[num]--;
        if(freqs[maxFreq].empty()) maxFreq--;

        return num;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */