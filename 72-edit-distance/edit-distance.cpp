class Solution {
    int getMinOps(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
        if(i < 0)   return j+1; 
        if(j < 0)   return i+1; 
        if(dp[i][j] != -1)  return dp[i][j];
        if(word1[i] == word2[j])
            return dp[i][j] = getMinOps(i-1, j-1, word1, word2, dp);
        int ins = 1 + getMinOps(i, j-1, word1, word2, dp);
        int del = 1 + getMinOps(i-1, j, word1, word2, dp);
        int repl = 1 + getMinOps(i-1, j-1, word1, word2, dp);

        return dp[i][j] = min(ins, min(del, repl));
    }
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return getMinOps(m-1, n-1, word1, word2, dp);
    }
};