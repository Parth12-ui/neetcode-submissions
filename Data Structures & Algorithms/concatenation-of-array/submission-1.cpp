class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> c_arr;
        c_arr = nums;
        c_arr.insert(c_arr.end(), nums.begin(), nums.end());
        return c_arr;
    }
};