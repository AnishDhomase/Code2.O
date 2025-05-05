typedef long long LL;
class Solution {
    int mod = 1e9 + 7;
    int getWays(int leftTop, int leftBottom, int n, vector<vector<int>> &dp){
        if(leftTop == n && leftBottom == n) return 1;
        if(leftTop > n || leftBottom > n) return 0;
        if(dp[leftTop][leftBottom] != -1)   return dp[leftTop][leftBottom];

        LL ways = 0;
        vector<int> dT = {1, 2, 2, 1}, dB = {1, 2, 1, 2};
        if(leftTop == leftBottom){
            for(int i=0; i<4; i++)
                ways = ((LL) ways + getWays(leftTop + dT[i], leftBottom + dB[i], n, dp)) % mod;
        }
        else if(leftTop < leftBottom){
            ways = ((LL) ways + getWays(leftTop + 2, leftBottom, n, dp)) % mod;
            ways = ((LL) ways + getWays(leftTop + 2, leftBottom + 1, n, dp)) % mod;
        }
        else{
            ways = ((LL) ways + getWays(leftTop, leftBottom + 2, n, dp)) % mod;
            ways = ((LL) ways + getWays(leftTop + 1, leftBottom + 2, n, dp)) % mod;
        }
        return dp[leftTop][leftBottom] = ways;
    }
public:
    int numTilings(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return getWays(0, 0, n, dp);
    }
};