class Solution {
    int mod = 1e9 + 7;
    int getWays(int i, int abs, int lateCnt, int n, vector<vector<vector<int>>> &dp){
        if(i == n+1)    return 1;
        if(dp[i][abs][lateCnt] != -1)   return dp[i][abs][lateCnt];

        long long ways = 0;
        ways = (long long) ((long long) ways + getWays(i+1, abs, 0, n, dp)) % mod;
        if(i==1 || abs == 0)        ways = (long long) ((long long) ways + getWays(i+1, abs + 1, 0, n, dp)) % mod;
        if(i==1 || lateCnt <= 1)    ways = (long long) ((long long) ways + getWays(i+1, abs, lateCnt + 1, n, dp)) % mod;

        return dp[i][abs][lateCnt] = ways;
    }
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        return getWays(1, 0, 0, n, dp);
    }
};