class Solution {
    int getLCS(int i, int j, string &str1, string &str2, vector<vector<int>> &dp){
        if(i==0 || j==0)  return 0;
        if(dp[i][j] != -1)  return dp[i][j];

        if(str1[i-1] == str2[j-1])
            return dp[i][j] = 1 + getLCS(i-1, j-1, str1, str2, dp);
        int p1 = getLCS(i-1, j, str1, str2, dp);
        int p2 = getLCS(i, j-1, str1, str2, dp);

        return dp[i][j] = max(p1, p2);
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return getLCS(n, m, text1, text2, dp);
        for(int j=0; j<=m; j++) dp[0][j] = 0;
        for(int i=0; i<=n; i++) dp[i][0] = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    continue;
                }
                int p1 = dp[i-1][j];
                int p2 = dp[i][j-1];
                dp[i][j] = max(p1, p2);
            }
        }
        return dp[n][m];   
    }
};