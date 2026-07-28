class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int cur_rot = 0;
        while (cur_rot < k){
            int temp = nums[nums.size()-1];
            for(int i = 0; i<nums.size(); i++){
                int curr = nums[i];
                nums[i] = temp;
                temp = curr;
            }

            cur_rot++;
        }
    }
};