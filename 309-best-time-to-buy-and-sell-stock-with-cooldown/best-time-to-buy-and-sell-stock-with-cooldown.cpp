class Solution {
    int getMaxProf(int i, int buy, vector<int> &prices, vector<vector<int>> &dp){
        int n = prices.size();
        if(i >= n)  return 0;
        if(dp[i][buy] != -1)    return dp[i][buy];

        int consider = 0, notConsider = 0;
        if(buy){
            consider = -prices[i] + getMaxProf(i+1, !buy, prices, dp);
            notConsider = getMaxProf(i+1, buy, prices, dp);
        }
        else{
            consider = prices[i] + getMaxProf(i+2, !buy, prices, dp);
            notConsider = getMaxProf(i+1, buy, prices, dp);
        }
        return dp[i][buy] = max(consider, notConsider);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return getMaxProf(0, 1, prices, dp);
    }
};