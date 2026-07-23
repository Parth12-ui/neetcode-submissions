class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> product;
        product.assign(nums.size(), 1);

        for(int i = 1; i<nums.size(); i++){
            if (i == 1) product[i] = nums[i-1];

            else product[i] = product[i-1] * nums[i-1];
        }

        int prod = nums[nums.size()-1];

        for(int i = nums.size()-2; i>=0; i--){
            product[i] *= prod;
            prod *= nums[i];
        }

        return product;
    }
};
