typedef long long LL;
class Solution {
    int mod = 1e9 + 7;
    int getWays(int pos, int steps, int arrLen, vector<vector<int>> &dp){
        if(steps == 0)  return pos == 0;
        if(dp[pos][steps] != -1)    return dp[pos][steps];

        LL ways = 0;
        ways = ((LL)ways + getWays(pos, steps-1, arrLen, dp)) % mod;
        if(pos-1 >= 0)
            ways = ((LL)ways + getWays(pos-1, steps-1, arrLen, dp)) % mod;
        if(pos+1 < arrLen)
            ways = ((LL)ways + getWays(pos+1, steps-1, arrLen, dp)) % mod;
            
        return dp[pos][steps] = ways;
    }
public:
    int numWays(int steps, int arrLen) {
        int n = min(steps + 1, arrLen);
        vector<vector<int>> dp(n, vector<int>(steps+1, -1));
        return getWays(0, steps, arrLen, dp);
    }
};