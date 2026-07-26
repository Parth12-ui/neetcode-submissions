class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        vector<int> result;
        while (left < right){
            int diff = target - (numbers[left] + numbers[right]);

            if (diff > 0) left++;
            else if (diff < 0) right--;
            else{
                result.push_back(left+1);
                result.push_back(right+1);

                return result;
            }
        }

        return result;
    }
};
