class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        vector<int> output;

        for(int num : nums){
            if (hashMap.count(num) == 0) hashMap[num] = 1;
            else hashMap[num]++;
        }

        for(auto& pair : hashMap){
            if (pair.second > nums.size() / 3) output.push_back(pair.first);
        }

        return output;
    }
};