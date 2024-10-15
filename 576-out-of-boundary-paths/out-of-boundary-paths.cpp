class Solution {
    int mod = 1e9 + 7;
    int getWays(int r, int c, int moves, int m, int n, vector<vector<vector<int>>> &dp){
        if(moves == 0)  return r==0 || c==0 || r == m+1 || c == n+1;
        if(r==0 || c==0 || r == m+1 || c == n+1)  return 1;
        if(dp[r][c][moves] != -1)   return dp[r][c][moves];

        int ways = 0;
        vector<int> dC = {0, 0, 1, -1};
        vector<int> dR = {1, -1, 0, 0};
        for(int i=0; i<4; i++){
            int newR = r + dR[i];
            int newC = c + dC[i];
            ways = (ways + getWays(newR, newC, moves-1, m, n, dp)) % mod;
        }
        return dp[r][c][moves] = ways;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(maxMove + 1, -1)));
        return getWays(startRow+1, startColumn+1, maxMove, m, n, dp);
    }
};