class Solution {
    int getTrees(int l, int r, vector<vector<int>> &dp){
        if(l >= r) return 1;
        if(dp[l][r] != -1)  return dp[l][r];

        int ways = 0;
        for(int par=l; par<=r; par++){
            ways += getTrees(l, par-1, dp) * getTrees(par+1, r, dp); 
        }
        return dp[l][r] = ways;
    }
public:
    int numTrees(int n) {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return getTrees(0, n-1, dp);
    }
};