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
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return isMatching(m, n, p, s, dp);
    }
};