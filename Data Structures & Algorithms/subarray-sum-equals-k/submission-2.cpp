class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        hashMap[0] = 1;
        int current_sum = 0;
        int n_sum = 0;

        for(int num : nums){
            current_sum += num;
            int diff = current_sum - k;
            n_sum += hashMap[diff];
            hashMap[current_sum]++;
        }

        return n_sum;
    }
};