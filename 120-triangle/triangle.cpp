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
        // vector<vector<int>> dp(n,vector<int>(n,1e9));
        // return getMinPath(0, 0, triangle, dp);
        vector<int> next(n), curr(n);
        for(int c=0; c<n; c++)
            next[c] = triangle[n-1][c];
        for(int r=n-2; r>=0; r--){
            for(int c=r; c>=0; c--){
                int down = next[c];
                int diag = next[c+1];

                curr[c] = min(down, diag) + triangle[r][c];
            }
            next = curr;
        }
        return next[0];
       
    }
};