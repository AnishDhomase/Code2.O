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
    int longestPalindromeSubseq(string s) {
        int  n = s.length();
        // vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        vector<int> prev(n+1, 0), curr(n+1, 0);
        string revS = s;
        reverse(revS.begin(), revS.end());
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == revS[j-1]){
                    curr[j] = 1 + prev[j-1];
                    continue;
                }
                int p1 = prev[j];
                int p2 = curr[j-1];
                curr[j] = max(p1, p2);
            }
            prev = curr;
        }
        return prev[n];
    }
};