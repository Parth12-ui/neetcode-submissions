class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        // target = num[1] + num[2]
        // hashmap tracks whether any other number requires the current number to hit target.
        unordered_map<int, int> hashMap;

        for(int i = 0; i<nums.size(); i++){
            //check if number is required already
            if (hashMap.count(nums[i]) > 0){
                result.push_back(hashMap[nums[i]]);
                result.push_back(i);

                return result;
            }

            // if not, add the number that should be added to current number to reach target
            int diff = target - nums[i];
            if (hashMap.count(diff) == 0) hashMap[diff] = i;
        }

        return result;
    }
};
