class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto& arr : matrix){
            int l = arr.size()-1;
            
            if (target <= arr[l]){
                int left = 0;
                int right = l;

                while (left <= right){
                    int mid = left + (right - left)/2;

                    if (arr[mid] == target) return true;
                    else if (arr[mid] > target) right = mid-1;
                    else left = mid + 1;
                }

                return false;
            }
        }

        return false;
    }
};
