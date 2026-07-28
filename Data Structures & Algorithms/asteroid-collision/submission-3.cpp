class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> state;
        vector<int> result;
        for(int a : asteroids){
            if (a < 0){
                bool survived = true;
                while(!state.empty()){
                    if (-a <= state.top()){
                        if (-a == state.top()) state.pop();
                        survived = false;
                        break;
                    }

                    state.pop();
                }

                if (survived) result.push_back(a);
            }
            else state.push(a);
        }

        stack<int> temp;
        while(!state.empty()){
            temp.push(state.top());
            state.pop();
        }
        state = temp;

        while(!state.empty()){
            result.push_back(state.top());
            state.pop();
        }

        return result;
    }
};