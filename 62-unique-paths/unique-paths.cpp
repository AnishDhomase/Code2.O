class Solution {
    int ways(int r, int c,  vector<vector<int>> &dp){
        if(r==0 || c==0)    return 1;
        if(r<0 || c<0)      return 0;
        if(dp[r][c] != -1)  return dp[r][c];
        int left = ways(r,c-1,dp); 
        int top = ways(r-1,c,dp);
        return dp[r][c] = left + top; 
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        // return ways(m-1,n-1,dp);
        for(int r=0; r<m; r++)  dp[r][0] = 1;
        for(int c=0; c<n; c++)  dp[0][c] = 1;
        for(int r=1; r<m; r++){
            for(int c=1; c<n; c++){
                int left = dp[r][c-1]; 
                int top = dp[r-1][c];
                dp[r][c] = left + top; 
            }
        }
        return dp[m-1][n-1];

        
    }
};