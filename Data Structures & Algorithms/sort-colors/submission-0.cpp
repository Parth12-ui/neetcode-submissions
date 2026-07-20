class Solution {
public:
    void sortColors(vector<int>& nums) {
        int countR = 0, countW = 0;

        for(int num : nums){
            if (num == 0) countR++;
            else if (num == 1) countW++;
        }

        for(int i = 0; i<nums.size(); i++){
            if (countR != 0){
                nums[i] = 0;
                countR--;
            }
            else if (countW != 0){
                nums[i] = 1;
                countW--;
            }
            else nums[i] = 2;
        }
    }
};