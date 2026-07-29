class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> combined;
        stack<double> s;
        for(int i = 0; i<position.size(); i++){
            combined.emplace_back(position[i], speed[i]);
        }
        sort(combined.begin(), combined.end());

        for(int i = 0; i<combined.size(); i++){
            double ft = (double)(target - combined[i].first) / combined[i].second;
            while(!s.empty() && s.top() <= ft){
                s.pop();
            }
            s.push(ft);
        }

        return s.size();
    }
};
