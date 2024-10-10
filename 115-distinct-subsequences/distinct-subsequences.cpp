class Solution {
    int getCnt(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(j < 0)   return 1;
        if(i < 0)   return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        int cnt = 0;
        if(s1[i] == s2[j])
            cnt += getCnt(i-1, j-1, s1, s2, dp);
        cnt += getCnt(i-1, j, s1, s2, dp);
        return dp[i][j] = cnt;
    }
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<int>> dp(m, vector<int>(n , -1));
        return getCnt(m-1, n-1, s, t, dp);
    }
};