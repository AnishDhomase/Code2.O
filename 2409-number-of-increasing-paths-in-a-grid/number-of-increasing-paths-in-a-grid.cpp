class Solution {
    int mod = 1e9 + 7;
    vector<int> dC = {0, 0, -1, 1};
    vector<int> dR = {-1, 1, 0, 0};
    int getWays(int r, int c, vector<vector<int>>& grid, vector<vector<int>> &dp){
        int rows = grid.size(), cols = grid[0].size();
        if(dp[r][c] != -1)  return dp[r][c];

        long long ways = 1;
        for(int i=0; i<4; i++){
            int adjC = c + dC[i], adjR = r + dR[i];
            if(adjC >=0 && adjC < cols && adjR >=0 && adjR < rows){
                if(grid[adjR][adjC] > grid[r][c]){
                    ways = ((long long)ways + getWays(adjR, adjC, grid, dp)) % mod;
                }
            }
        }
        return dp[r][c] = ways;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        long long ways = 0;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++)
                ways = ((long long)ways + getWays(r, c, grid, dp)) % mod;         
        }
        return ways;
    }
};