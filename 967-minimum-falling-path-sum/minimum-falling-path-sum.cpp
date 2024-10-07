class Solution {
    int getMinPathSum(int r, int c, vector<vector<int>>& matrix, vector<vector<int>> &dp){
        if(r==0)    return matrix[r][c];
        if(dp[r][c] != 1e9) return dp[r][c];

        int n = matrix.size();
        int up, left = 1e9, right = 1e9;
        up = getMinPathSum(r-1, c, matrix, dp);
        if(c-1 >= 0)
            left = getMinPathSum(r-1, c-1, matrix, dp);
        if(c+1 < n)
            right = getMinPathSum(r-1, c+1, matrix, dp);

        return dp[r][c] = min(up, min(left, right)) + matrix[r][c];
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n,1e9));
        int minP = 1e9, pathVal;
        // for(int c=0; c<n; c++){
        //     pathVal = getMinPathSum(n-1, c, matrix, dp);
        //     minP = min(minP, pathVal);
        // }
        for(int c=0; c<n; c++)
            dp[0][c] = matrix[0][c];
        for(int r=1; r<n; r++){
            for(int c=0; c<n; c++){
                int up, left = 1e9, right = 1e9;
                up = dp[r-1][c];
                if(c-1 >= 0)
                    left = dp[r-1][c-1];
                if(c+1 < n)
                    right = dp[r-1][c+1];

                dp[r][c] = min(up, min(left, right)) + matrix[r][c];
            }
        }
        for(int c=0; c<n; c++)
            minP = min(minP, dp[n-1][c]);
        return minP;
    }
};