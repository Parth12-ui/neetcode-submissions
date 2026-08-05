class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size()-1;
        
        while(left <= right){
            int mid = left + (right - left)/2;
            if (left == mid){
                if (nums[left] < nums[right]) return nums[left];
                else return nums[right];
            }
            
            if (nums[left] > nums[mid]){
                if (nums[mid] < nums[right]) right = mid;
                else{
                    if (nums[left] > nums[right]) left = mid;
                    else right = mid;
                }
            }
            else if (nums[left] < nums[mid]){
                if (nums[mid] <= nums[right]) return nums[left];
                else left = mid;                    
            }
        }
    }
};
