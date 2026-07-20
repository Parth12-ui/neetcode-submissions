class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return search(nums, 0, nums.size(), target);
    }

    int search(vector<int>& nums, int bottom, int top, int target){
        if (top == bottom) return top;

        int mid = (top + bottom) / 2;

        if (nums[mid] >= target) return search(nums, bottom, mid, target);
        else return search(nums, mid+1, top, target);
    }
};