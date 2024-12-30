typedef long long LL;
int mod = 1e9 + 7;
class Solution {
    int getWays(int len, int zero, int one, int low, int high, vector<int> &dp){
        LL ways = 0;
        if(low <= len && len <= high) ways ++;
        if(len > high) return 0;
        if(dp[len] != -1)   return dp[len];


        // add zero
        ways = ((LL)(ways) + getWays(len + zero, zero, one, low, high, dp)) % mod;
        // add one
        ways = ((LL)(ways) + getWays(len + one, zero, one, low, high, dp)) % mod;

        return dp[len] = ways;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, -1);
        return getWays(0, zero, one, low, high, dp);
    }
};