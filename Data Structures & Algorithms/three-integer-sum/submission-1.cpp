class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>result;

        for(int i = 0; i<nums.size(); i++){

            if (i > 0 && nums[i] == nums[i-1]) continue;
            int left = i+1;
            int right = nums.size()-1;

            while(left < right){
                int diff = nums[i] + nums[left] + nums[right];
                if (diff > 0) right--;
                else if (diff < 0) left++;
                else{
                    vector<int>pairs;
                    pairs.push_back(nums[i]);
                    pairs.push_back(nums[left]);
                    pairs.push_back(nums[right]);

                    result.push_back(pairs);
                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left-1]) left++;
                }
            }
        }

        return result;
    }
};
