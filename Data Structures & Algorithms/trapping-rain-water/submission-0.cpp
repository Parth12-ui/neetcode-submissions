class Solution {
public:
    int trap(vector<int>& height) {
        int max_area = 0;

        vector<int> t_area(height.size()+1, 0);
        int cur_max = -1, left = 0, right = height.size()-1;
        while(left<=right){
            int cur_area = min(height[left], height[right]);

            if (cur_area > cur_max) cur_max = cur_area;
            t_area[left] = cur_max;
            t_area[right] = cur_max;

            if (height[left] < height[right]) left++;
            else right--;
        }

        for(int i = 0; i<height.size(); i++){
            int cur_block = t_area[i] - height[i];

            if (cur_block < 0) cur_block = 0;

            max_area += cur_block;
        }

        return max_area;
    }
};
