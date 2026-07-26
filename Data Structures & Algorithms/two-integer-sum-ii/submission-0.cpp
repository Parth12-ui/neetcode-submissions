class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> hashMap;
        vector<int> result;

        for(int i = 0; i<numbers.size(); i++){
            int diff = target - numbers[i];

            if (hashMap.count(diff) != 0){
                result.push_back(hashMap[diff]+1);
                result.push_back(i+1);

                return result;
            }

            hashMap[numbers[i]] = i;
        }

        return result;
    }
};
