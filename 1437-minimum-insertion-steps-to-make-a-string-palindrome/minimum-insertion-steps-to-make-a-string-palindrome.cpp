class Solution {
    int getLCS(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i==0 || j==0)  return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i-1] == s2[j-1])
            return dp[i][j] = 1 + getLCS(i-1, j-1, s1, s2, dp);
        int p1 = getLCS(i-1, j, s1, s2, dp);
        int p2 = getLCS(i, j-1, s1, s2, dp);
        return dp[i][j] = max(p1, p2);
    }
public:
    int minInsertions(string s) {
        int n = s.length();
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        string rev = s;
        reverse(rev.begin(), rev.end());
        // return n - getLCS(n, n, s, rev, dp);
        vector<int> prev(n+1, 0), curr(n+1, 0);
        // for(int i=0; i<=n; i++) dp[i][0] = 0;
        // for(int j=0; j<=n; j++) dp[0][j] = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == rev[j-1]){
                    curr[j] = 1 + prev[j-1];
                    continue;
                }
                int p1 = prev[j];
                int p2 = curr[j-1];
                curr[j] = max(p1, p2);
            }
            prev = curr;
        }
        return n - prev[n];
    }
};