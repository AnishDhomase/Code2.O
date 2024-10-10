class Solution {
    int getLCS(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i<0 || j<0)  return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j])
            return dp[i][j] = 1 + getLCS(i-1, j-1, s1, s2, dp);
        int p1 = getLCS(i-1, j, s1, s2, dp);
        int p2 = getLCS(i, j-1, s1, s2, dp);
        return dp[i][j] = max(p1, p2);
    }
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        string rev = s;
        reverse(rev.begin(), rev.end());
        return n - getLCS(n-1, n-1, s, rev, dp);
    }
};