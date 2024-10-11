class Solution {
    bool isMatching(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(j < 0){
            while(i >= 0){
                if(s1[i] != '*')
                    return false;
                i --;
            }
            return true;
        }
        if(i<0) return false;
        if(dp[i][j] != -1)  return dp[i][j];

        if(s1[i] == '?')
            return dp[i][j] = isMatching(i-1, j-1, s1, s2, dp);
        if(s1[i] == '*'){
            bool p1 = isMatching(i-1, j, s1, s2, dp);
            bool p2 = isMatching(i, j-1, s1, s2, dp);
            return dp[i][j] = p1 || p2;
        }
        if(s1[i] == s2[j])  return dp[i][j] = isMatching(i-1, j-1, s1, s2, dp);
        return dp[i][j] = false;
        
    }
public:
    bool isMatch(string s, string p) {
        int m = p.length(), n = s.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return isMatching(m-1, n-1, p, s, dp);
    }
};