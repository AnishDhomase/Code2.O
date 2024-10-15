class Solution {
    int mod = 1e9 + 7;
    int getWays(int i, int t, int k, vector<vector<int>> &dp){
        if(i == 0)  return t == 0;
        if(t == 0)  return i == 0;
        if(dp[i][t] != -1)  return dp[i][t];

        int ways = 0;
        for(int val = 1; val <= k; val++){
            if(t >= val)
                ways = (ways + getWays(i-1, t-val, k, dp)) % mod; 
            else break;    
        }
        return dp[i][t] = ways;
        
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int> (target + 1, -1));
        return getWays(n, target, k, dp);
    }
};