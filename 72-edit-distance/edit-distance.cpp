class Solution {
    int getMinOps(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
        if(i == 0)   return j; 
        if(j == 0)   return i; 
        if(dp[i][j] != -1)  return dp[i][j];
        if(word1[i-1] == word2[j-1])
            return dp[i][j] = getMinOps(i-1, j-1, word1, word2, dp);
        int ins = 1 + getMinOps(i, j-1, word1, word2, dp);
        int del = 1 + getMinOps(i-1, j, word1, word2, dp);
        int repl = 1 + getMinOps(i-1, j-1, word1, word2, dp);

        return dp[i][j] = min(ins, min(del, repl));
    }
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        // return getMinOps(m, n, word1, word2, dp);
        for(int j=0; j<=n; j++) dp[0][j] = j;
        for(int i=0; i<=m; i++) dp[i][0] = i;

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                    continue;
                }
                int ins = 1 + dp[i][j-1];
                int del = 1 + dp[i-1][j];
                int repl = 1 + dp[i-1][j-1];
                dp[i][j] = min(ins, min(del, repl));
            }
        }
        return dp[m][n];
        
    }
};