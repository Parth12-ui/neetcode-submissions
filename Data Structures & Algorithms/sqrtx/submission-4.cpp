class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int ans = 0;
        while (left <= right){
            int mid = left + (right-left)/2;
            long long product = 1;
            for(int i = 0; i<2; i++) product *= mid;
            
            if (product == x) return mid;
            if (product < x) {
                left = mid + 1;
                ans = mid;
            }
            else if (product > x) right = mid - 1;
        }
        
        return ans;
    }
};