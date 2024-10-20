class Solution {
    int getMaxProfit(int i, int trans,  vector<int> &prices, vector<vector<int>> &dp){
        int n = prices.size();
        if(i == n)  return 0;
        if(trans == 0)  return 0;
        if(dp[i][trans] != -1)  return dp[i][trans];

        int sign = trans % 2 == 0 ? -1 : 1;
        int notConsider = getMaxProfit(i+1, trans, prices, dp);
        int consider = sign * prices[i] + getMaxProfit(i+1, trans-1, prices, dp);

        return dp[i][trans] = max(notConsider, consider);
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2*k+1, -1));
        return getMaxProfit(0, 2*k, prices, dp);
    }
};