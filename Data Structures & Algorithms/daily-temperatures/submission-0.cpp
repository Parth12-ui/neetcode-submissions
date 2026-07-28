class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> result(temperatures.size(), 0);

        for(int i = temperatures.size() - 1; i>= 0; i--){
            int nd = 1;
            stack<int> temp;
            bool temp_check = true;
            while (!s.empty()){
                if (s.top() > temperatures[i]) temp_check = false;

                if (temp_check) nd++;
                temp.push(s.top());
                s.pop();
            }

            if (temp_check == false) result[i] = nd;
            while(!temp.empty()){
                s.push(temp.top());
                temp.pop();
            }
            
            s.push(temperatures[i]);
        }

        return result;
    }
};
