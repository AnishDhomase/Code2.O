class Solution {
    int getMaxMoves(int r, int c, vector<vector<int>>& grid, vector<vector<int>> &dp){
        int rows = grid.size(), cols = grid[0].size();
        if(c == cols-1) return 0;
        if(dp[r][c] != -1)  return dp[r][c];

        int maxMoves = 0;
        for(int dR = -1; dR <= 1; dR ++){
            int adjR = r + dR, adjC = c + 1;
            if(adjR >=0 && adjR < rows){
                if(grid[adjR][adjC] > grid[r][c]){
                    int moves = 1 + getMaxMoves(adjR, adjC, grid, dp);
                    maxMoves = max(maxMoves, moves);
                }
            } 
        }
        return dp[r][c] = maxMoves;
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int maxMoves = 0;
        vector<vector<int>> dp(rows, vector<int>(cols, -1));

        for(int r=0; r<rows; r++){
            int moves = getMaxMoves(r, 0, grid, dp);
            maxMoves = max(maxMoves, moves);
        }
        return maxMoves;
    }
};