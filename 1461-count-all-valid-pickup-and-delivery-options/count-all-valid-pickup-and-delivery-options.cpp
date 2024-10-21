class Solution {
    int mod = 1e9 + 7;
    int getWays(int p, int d, vector<vector<int>> &dp){
        if(p == 0 && d == 0)    return 1;
        if(dp[p][d] != -1)  return dp[p][d];

        long long ways = 0;
        if(p > 0)   
            ways = (long long)(ways + ((long long)p * getWays(p-1, d+1, dp)) % mod) % mod;
        if(d > 0)  
            ways = (long long)(ways + ((long long)d * getWays(p, d-1, dp)) % mod) % mod;

        return dp[p][d] = ways;
    }
public:
    int countOrders(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return getWays(n, 0, dp);
    }
};