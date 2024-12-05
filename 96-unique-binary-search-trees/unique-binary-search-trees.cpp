class Solution {
    int getTrees(int l, int r, vector<int> &dp){
        if(l >= r) return 1;
        if(dp[r-l] != -1)  return dp[r-l];

        int ways = 0;
        for(int par=l; par<=r; par++){
            ways += getTrees(l, par-1, dp) * getTrees(par+1, r, dp); 
        }
        return dp[r-l] = ways;
    }
public:
    int numTrees(int n) {
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<int> dp(n, -1);
        return getTrees(0, n-1, dp);    
    }
};