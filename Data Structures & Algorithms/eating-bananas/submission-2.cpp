class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_piles = 0;
        for(int i = 0; i<piles.size(); i++){
            if (piles[i] > max_piles) max_piles = piles[i];
        }
        
        int valid = max_piles;
        int left = 1, right = max_piles;
        while(left <= right){
            int mid = left + (right - left)/2;

            int hours = 0;
            for(int i = 0; i<piles.size(); i++) hours += ceil((double)piles[i]/mid);
            if (hours <= h && mid < valid) valid = mid;

            if (hours > h) left = mid + 1;
            else right = mid - 1;
        }
        
        return valid;
    }
};
