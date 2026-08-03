class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // Edge case: Need at least 4 numbers
        if (n < 4) return result;
        
        // 1. Sort the array for the two-pointer approach
        sort(nums.begin(), nums.end()); 
        
        for (int j = 0; j < n - 3; j++) {
            // Skip duplicates for the first number
            if (j > 0 && nums[j] == nums[j-1]) continue;
            
            // 2. Inner loop must start at j + 1
            for (int i = j + 1; i < n - 2; i++) {
                // Skip duplicates for the second number
                if (i > j + 1 && nums[i] == nums[i-1]) continue;
                
                int left = i + 1;
                int right = n - 1;
                
                while (left < right) {
                    // 3. Add all FOUR numbers, cast to long long to prevent overflow
                    long long sum = (long long)nums[j] + nums[i] + nums[left] + nums[right];
                    
                    // 4. Compare against 'target', not 0
                    if (sum > target) {
                        right--;
                    } 
                    else if (sum < target) {
                        left++;
                    } 
                    else {
                        // Found a valid quadruplet
                        result.push_back({nums[j], nums[i], nums[left], nums[right]});
                        
                        left++;
                        right--;
                        
                        // Skip duplicates for the third and fourth numbers
                        while (left < right && nums[left] == nums[left-1]) left++;
                        while (left < right && nums[right] == nums[right+1]) right--;
                    }
                }
            }
        }
        
        // 5. Return the final result
        return result;
    }
};