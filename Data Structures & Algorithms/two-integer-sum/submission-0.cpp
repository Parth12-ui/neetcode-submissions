class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        unordered_map<int, int> hashMap;

        for(int i = 0; i<nums.size(); i++){
            if (hashMap.count(nums[i]) > 0){
                result.push_back(hashMap[nums[i]]);
                result.push_back(i);

                return result;
            }

            int diff = target - nums[i];
            if (hashMap.count(diff) == 0) hashMap[diff] = i;
        }

        return result;
    }
};
