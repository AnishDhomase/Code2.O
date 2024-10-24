class Solution {
    int getMaxProd(int n, int breaks, vector<vector<int>> &dp){
        if(n == 1)  return 1;
        if(dp[n][breaks] != -1) return dp[n][breaks];

        int maxProd = breaks ? n : 0;
        for(int i=1; i<=n/2; i++){
            int prod = getMaxProd(i, 1, dp) * getMaxProd(n-i, 1, dp);
            maxProd = max(maxProd, prod);
        }
        return dp[n][breaks] = maxProd;
    }
public:
    int integerBreak(int n) {
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return getMaxProd(n, 0, dp);
    }
};