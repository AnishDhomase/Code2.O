typedef long long LL;
class Solution {
    int mod = 1e9 + 7;
    int getWays(int n, int prevPrev, int prev, vector<vector<vector<int>>> &dp){
        if(n == 0)  return 1;
        if(dp[n][prevPrev][prev] != -1) return dp[n][prevPrev][prev];
        LL ways = 0;
        for(int dice=1; dice<=6; dice++){
            if(dice == prevPrev || dice == prev)    continue;
            int gcd = prev == 0 ? 1 : __gcd(prev, dice);
            if(gcd != 1)    continue;

            ways = ((LL) ways + getWays(n-1, prev, dice, dp)) % mod;
        }
        return dp[n][prevPrev][prev] = ways;
    }
public:
    int distinctSequences(int n) {
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(7, vector<int>(7, -1)));
        // return getWays(n, 0, 0, dp);
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(7, vector<int>(7, 1)));
        vector<vector<int>> prevRow(7, vector<int>(7, 1)), currRow(7, vector<int>(7, 1));
        for(int N=1; N<=n; N++){
            for(int prevPrev=0; prevPrev<=6; prevPrev ++){
                for(int prev=0; prev<=6; prev ++){
                    LL ways = 0;
                    for(int dice=1; dice<=6; dice++){
                        if(dice == prevPrev || dice == prev)    continue;
                        int gcd = prev == 0 ? 1 : __gcd(prev, dice);
                        if(gcd != 1)    continue;

                        ways = ((LL) ways + prevRow[prev][dice]) % mod;
                    }
                    currRow[prevPrev][prev] = ways;
                }
            }
            prevRow = currRow;
        }
        return currRow[0][0];
    }
};