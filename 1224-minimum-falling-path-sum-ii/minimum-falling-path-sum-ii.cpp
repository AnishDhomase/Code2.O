class Solution {
    int getMinPath(int r, int c, vector<vector<int>>& grid, vector<vector<int>> &dp){
        int minVal = 1e9, n = grid.size();
        if(r == 0){
            for(int col=0; col<n; col++){
                if(col == c)    continue;
                minVal = min(minVal, grid[0][col]);
            }
            return minVal;
        }
        if(dp[r][c] != 1e9) return dp[r][c];

        for(int col=0; col<n; col++){
            if(col == c)    continue;
            int pathVal = grid[r][col] + getMinPath(r-1, col, grid, dp);
            minVal =  min(minVal, pathVal);
        }
        return dp[r][c] = minVal;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n+1, 1e9));
        return getMinPath(n-1, n, grid, dp);
    }
};