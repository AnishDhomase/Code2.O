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
        // return minSum(R-1, C-1, grid, dp);
        int neg = 1e9;
        dp[0][0] = grid[0][0];
        for(int r=0; r<R; r++){
            for(int c=0; c<C; c++){
                if(r==0 && c==0)    continue;
                int left = c-1 < 0 ? neg : dp[r][c-1];
                int top = r-1 < 0 ? neg : dp[r-1][c];
                dp[r][c] = min(left, top) + grid[r][c];
            }
        }
        return dp[R-1][C-1];
    }
};