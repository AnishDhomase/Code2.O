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
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return getLCS(n, m, text1, text2, dp);
        vector<int> prev(m+1), curr(m+1, 0);
        for(int j=0; j<=m; j++) prev[j] = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(text1[i-1] == text2[j-1]){
                    curr[j] = 1 + prev[j-1];
                    continue;
                }
                int p1 = prev[j];
                int p2 = curr[j-1];
                curr[j] = max(p1, p2);
            }
            prev = curr;
        }
        return prev[m];   
    }
};