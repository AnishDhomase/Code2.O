class Solution {
    int getLCS(int i, int j, string &str1, string &str2, vector<vector<int>> &dp){
        if(i<0 || j<0)  return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        if(str1[i] == str2[j])
            return dp[i][j] = 1 + getLCS(i-1, j-1, str1, str2, dp);
        int p1 = getLCS(i-1, j, str1, str2, dp);
        int p2 = getLCS(i, j-1, str1, str2, dp);

        return dp[i][j] = max(p1, p2);
    }
public:
    int longestPalindromeSubseq(string s) {
        int  n = s.length();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        string revS = s;
        reverse(revS.begin(), revS.end());
        return getLCS(n-1, n-1, s, revS, dp);
    }
};