class Solution {
    int ways(int r, int c, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp){
        if(r<0 || c<0)      return 0;
        if(obstacleGrid[r][c] == 1) return 0;
        if(r==0 & c==0)    return 1;
        if(dp[r][c] != -1)  return dp[r][c];
        int left = ways(r, c-1, obstacleGrid, dp); 
        int top = ways(r-1, c, obstacleGrid, dp);
        return dp[r][c] = left + top; 
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols,-1));
        // return ways(rows-1, cols-1, obstacleGrid, dp);
        int neg = 0;
        dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(r==0 & c==0) continue;
                if(obstacleGrid[r][c] == 1){
                    dp[r][c] = 0;
                    continue;
                }
                int left = c-1 < 0 ? neg : dp[r][c-1];
                int top = r-1 < 0 ? neg : dp[r-1][c];
                dp[r][c] = left + top;
            }
        }
        return dp[rows-1][cols-1];
    }
};