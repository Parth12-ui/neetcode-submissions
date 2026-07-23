class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashset(nums.begin(), nums.end());
        int lc = 0;

        for(int num : hashset){
            if (hashset.count(num-1) == 0){
                int current_length = 0, current_num = num;

                while(hashset.count(current_num) == 1){
                    current_num++;
                    current_length++;
                }

                if (current_length > lc) lc = current_length;
            }
        }

        return lc;
    }
};
