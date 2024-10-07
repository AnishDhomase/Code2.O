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
        // vector<vector<int>> dp(n, vector<int>(n,1e9));
        int minP = 1e9, pathVal;
        // for(int c=0; c<n; c++){
        //     pathVal = getMinPathSum(n-1, c, matrix, dp);
        //     minP = min(minP, pathVal);
        // }
        vector<int> prev(n), curr(n);
        for(int c=0; c<n; c++)
            prev[c] = matrix[0][c];
        for(int r=1; r<n; r++){
            for(int c=0; c<n; c++){
                int up, left = 1e9, right = 1e9;
                up = prev[c];
                if(c-1 >= 0)
                    left = prev[c-1];
                if(c+1 < n)
                    right = prev[c+1];

                curr[c] = min(up, min(left, right)) + matrix[r][c];
            }
            prev = curr;
        }
        for(int c=0; c<n; c++)
            minP = min(minP, prev[c]);
        return minP;
    }
};