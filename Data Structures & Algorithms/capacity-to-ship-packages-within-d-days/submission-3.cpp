class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int min_weight = 0, sum = 0;
        for(int i = 0; i<weights.size(); i++){
            if (min_weight < weights[i]) min_weight = weights[i];
            sum += weights[i];
        }

        int left = min_weight;
        int right = sum;
        min_weight = sum;
        while(left <= right){
            int mid = left + (right - left)/2;

            int curr = 0, cur_days = 0;
            for(int i = 0; i<weights.size(); i++){
                if (curr + weights[i] > mid){
                    curr = 0;
                    cur_days++;
                    i--;
                }
                else curr += weights[i];
            }
            if (cur_days < days && mid < min_weight) min_weight = mid;

            if (cur_days >= days) left = mid + 1;
            else right = mid - 1;
        }

        return min_weight;
    }
};