class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        int k = 0;
        for(int i = 0; i<nums.size(); i++){
            if (hashMap.count(nums[i]) == 0){
                hashMap[nums[i]] = 1;
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};