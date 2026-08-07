class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> timeMap;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        timeMap[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if (timeMap.count(key) == 0) return "";

        vector<pair<int, string>>& arr = timeMap[key];
    
        int left = 0, right = arr.size()-1;
        if (arr[left].first > timestamp) return "";
        int cur_result = left;

        while(left <= right){
            int mid = left + (right - left)/2;
            if (arr[mid].first == timestamp) return arr[mid].second;

            int diff = timestamp - arr[cur_result].first;
            int new_diff = timestamp - arr[mid].first;

            if (new_diff > 0 && new_diff < diff) cur_result = mid;

            if (arr[mid].first < timestamp) left = mid + 1;
            else right = mid - 1;
        }

        return timeMap[key][cur_result].second;
    }
};
