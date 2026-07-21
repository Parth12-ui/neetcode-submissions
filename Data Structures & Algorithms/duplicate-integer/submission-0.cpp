class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> hashSet;
        for(int i = 0; i<nums.size(); i++){
            if (hashSet.count(nums[i]) == 0) hashSet.insert(nums[i]);
            else return 1;
        }

        return 0;
    }
};