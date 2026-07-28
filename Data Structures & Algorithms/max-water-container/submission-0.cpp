class Solution {
public:
    int maxArea(vector<int>& heights) {

        int max_area = -1, left = 0, right = heights.size()-1;
        while(left < right){
            int cur_area = (right - left) * min(heights[left], heights[right]);
            if (cur_area > max_area) max_area = cur_area;

            if (heights[left] < heights[right]) left++;
            else right--;
        }

        return max_area;
    }
};
