class Solution {
    int getMinTurns(int i, int j, int prev, string &s,  vector<vector<vector<int>>> &dp){
        if(i > j)   return prev;
        if(i == j)  return 1;
        if(dp[i][j][prev] != -1)    return dp[i][j][prev];

        int minTurns = 1e9;
        int toPrint = s[i], p;
        for(p=i+1; p<=j; p++)
            if(s[p] != toPrint) break;
        int restStart = p;
        int printSeparately = 1 + getMinTurns(p, j, 0, s, dp);
        minTurns = min(minTurns, printSeparately);

        for(; p<=j; p++){
            if(s[p] == toPrint){
                int printCombinelyLater = 0 + getMinTurns(restStart, p-1, 0, s, dp) + getMinTurns(p, j, 1, s, dp);
                minTurns = min(minTurns, printCombinelyLater);
            }
        }
        return dp[i][j][prev] = minTurns;
    }
public:
    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return getMinTurns(0, n-1, 0, s, dp);
    }
};