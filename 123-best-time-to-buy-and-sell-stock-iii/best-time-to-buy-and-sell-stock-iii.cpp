class Solution {
    int getMaxProfit(int i, int trans, vector<int> &prices, vector<vector<int>> &dp){
        int n = prices.size();
        if(i == n)  return 0;
        if(trans == 0)  return 0;
        if(dp[i][trans] != -1)  return dp[i][trans];
        
        int sign = trans % 2 ? 1 : -1;
        int consider = sign * prices[i] + getMaxProfit(i+1, trans-1, prices, dp);
        int notConsider = getMaxProfit(i+1, trans, prices, dp);

        return dp[i][trans] = max(consider, notConsider);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(5, -1));
        // return getMaxProfit(0, 4, prices, dp);
        // vector<vector<int>> dp(n+1, vector<int>(5, 0));
        vector<int> curr(5, 0), next(5, 0);
        for(int i = n-1; i>=0; i--){
            for(int trans = 1; trans <= 4; trans ++){
                int sign = trans % 2 ? 1 : -1;
                int consider = sign * prices[i] + next[trans-1];
                int notConsider = next[trans];

                curr[trans] = max(consider, notConsider);
            }
            next = curr;
        }
        return next[4];
        
    }
};