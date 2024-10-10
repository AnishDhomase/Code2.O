class Solution {
    int getLCS(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i==0 || j==0)    return 0;
        if(dp[i][j] != -1)  return dp[i][j];

        if(s1[i-1] == s2[j-1])
            return dp[i][j] = 1 + getLCS(i-1, j-1, s1, s2, dp);
        int p1 = getLCS(i-1, j, s1, s2, dp);
        int p2 = getLCS(i, j-1, s1, s2,dp);

        return dp[i][j] = max(p1, p2);
    }
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        int lcs = getLCS(m, n, word1, word2, dp);
        return m - lcs + n - lcs;
    }
};