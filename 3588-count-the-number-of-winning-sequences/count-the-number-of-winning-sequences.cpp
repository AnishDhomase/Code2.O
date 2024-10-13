class Solution {
    int mod = 1e9 + 7;
    vector<char> ops = {'F', 'W', 'E'};
    int getPointEarned(int alice, int bob){
        if(alice == bob)    return 0;
        if(alice == 'F' && bob == 'E')  return -1;
        if(alice == 'W' && bob == 'F')  return -1;
        if(alice == 'E' && bob == 'W')  return -1;
        return 1;
    }
    int getSubseq(int i, int lastMove, int points, string &s, vector<vector<vector<int>>> &dp){
        int n = s.length();
        if(i<0) return points-n > 0;
        if(dp[i][lastMove][points] != -1)   return dp[i][lastMove][points]; 

        int ways = 0;
        for(int o=0; o<3; o++){
            if(o != lastMove){
                int pointEarned = getPointEarned(s[i], ops[o]);
                ways = (ways + getSubseq(i-1, o, points + pointEarned, s, dp)) % mod;
            }
        }
        return dp[i][lastMove][points] = ways;
    }
public:
    int countWinningSequences(string s) {
        int n = s.length();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(4, vector<int>(2*n+1 , -1)));
        return getSubseq(n-1, 3, n, s, dp);
    }
};