class Solution {
    int minSum(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(r<0 || c<0)  return 1e9;
        if(r==0 && c==0)    return grid[0][0];
        if(dp[r][c] != -1)  return dp[r][c];
        int left = minSum(r, c-1, grid, dp);
        int top = minSum(r-1, c, grid, dp);
        return dp[r][c] = min(left, top) + grid[r][c];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        vector<vector<int>> dp(R, vector<int>(C,-1));
        return minSum(R-1, C-1, grid, dp);
    }
};