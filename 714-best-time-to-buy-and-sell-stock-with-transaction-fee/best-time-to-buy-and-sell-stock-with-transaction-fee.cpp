class Solution {
    int getMaxProfit(int i, int buy, vector<int>& prices, int fee, vector<vector<int>> &dp){
        int n = prices.size();
        if(i == n)  return 0;
        if(dp[i][buy] != -1)    return dp[i][buy];

        int consider, notConsider;
        if(buy){
            consider = -prices[i] + getMaxProfit(i+1, 0, prices, fee, dp);
            notConsider = getMaxProfit(i+1, 1, prices, fee, dp);
        }
        else{
            consider = prices[i] - fee + getMaxProfit(i+1, 1, prices, fee, dp);
            notConsider = getMaxProfit(i+1, 0, prices, fee, dp);
        }
        return dp[i][buy] = max(consider, notConsider);
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return getMaxProfit(0, 1, prices, fee, dp);
    }
};