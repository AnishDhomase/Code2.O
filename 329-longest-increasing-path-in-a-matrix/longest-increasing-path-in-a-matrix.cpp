class Solution {
    vector<int> dC = {0, 0, 1, -1};
    vector<int> dR = {1, -1, 0, 0};
    int getLongestPath(int r, int c, vector<vector<int>>& matrix, vector<vector<int>> &dp){
        int rows = matrix.size(), cols = matrix[0].size();
        if(dp[r][c] != -1)  return dp[r][c];

        int longest = 1;
        for(int i=0; i<4; i++){
            int adjC = c + dC[i], adjR = r + dR[i];
            if(adjC >= 0 && adjC < cols && adjR >= 0 && adjR < rows){
                if(matrix[adjR][adjC] > matrix[r][c]){
                    int path = 1 + getLongestPath(adjR, adjC, matrix, dp);
                    longest = max(longest, path);
                }
            }
        }
        return dp[r][c] = longest;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int longest = 1;
        int rows = matrix.size(), cols = matrix[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                int path = getLongestPath(r, c, matrix, dp);
                longest = max(longest, path);
            }
        }
        return longest;
    }
};