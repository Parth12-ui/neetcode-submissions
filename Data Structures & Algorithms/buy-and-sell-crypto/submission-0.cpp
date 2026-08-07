class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_buy = prices[0];
        
        for(int i = 0; i < prices.size(); i++){
            int current_p = prices[i];

            int profit = current_p - min_buy;
            if (profit > max_profit) max_profit = profit;

            if (current_p < min_buy) min_buy = current_p;
        }
        
        return max_profit;
    }
};
