class Solution {
    int getMinPath(int r, int c, vector<vector<int>>& triangle, vector<vector<int>> &dp){
        int n = triangle.size();
        if(r == n-1)    return triangle[n-1][c];
        if(dp[r][c] != 1e9) return dp[r][c];
        int down = getMinPath(r+1, c, triangle, dp);
        int diag = getMinPath(r+1, c+1, triangle, dp);

        return dp[r][c] = min(down, diag) + triangle[r][c];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,1e9));
        return getMinPath(0, 0, triangle, dp);
       
    }
};