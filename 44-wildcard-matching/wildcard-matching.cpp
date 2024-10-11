class Solution {
    bool isMatching(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(j == 0){
            while(i-1 >= 0){
                if(s1[i-1] != '*')
                    return false;
                i --;
            }
            return true;
        }
        if(i == 0) return false;
        if(dp[i][j] != -1)  return dp[i][j];

        if(s1[i-1] == '?')
            return dp[i][j] = isMatching(i-1, j-1, s1, s2, dp);
        if(s1[i-1] == '*'){
            bool p1 = isMatching(i-1, j, s1, s2, dp);
            bool p2 = isMatching(i, j-1, s1, s2, dp);
            return dp[i][j] = p1 || p2;
        }
        if(s1[i-1] == s2[j-1])  return dp[i][j] = isMatching(i-1, j-1, s1, s2, dp);
        return dp[i][j] = false;
        
    }
public:
    bool isMatch(string s, string p) {
        int m = p.length(), n = s.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        // return isMatching(m, n, p, s, dp);
        for(int i=0; i<=m; i++){
            int I = i;
            bool flag = true;
            while(I-1 >= 0){
                if(p[I-1] != '*'){
                    dp[i][0] = 0;
                    flag = false;;
                    break;
                }
                I --;
            }
            if(flag)
                dp[i][0] = 1;
        }
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(p[i-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[i-1] == '*'){
                    bool p1 = dp[i-1][j];
                    bool p2 = dp[i][j-1];
                    dp[i][j] = p1 || p2;
                }
                else if(p[i-1] == s[j-1])  dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 0;
            }
        }
        return dp[m][n];
    }
};