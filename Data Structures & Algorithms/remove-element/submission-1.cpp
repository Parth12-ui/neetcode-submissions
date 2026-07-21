class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size(), i = 0;

        //iterate through elements of nums.
        while(i < k){
            // if number is equal to val, we swap it with the last valid number and decrease size by 1.
            if (nums[i] == val){
                nums[i] = nums[k-1];
                // decreasing size of valid array
                k--;
            }

            // else, move to next number
            else i++;
        }

        return k;
    }
};