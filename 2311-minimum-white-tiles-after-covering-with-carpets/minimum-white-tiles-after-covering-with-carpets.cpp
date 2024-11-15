class Solution {
    int getMinWhites(int i, int carpets, int cLen, string &floor, vector<vector<int>> &dp){
        int n = floor.size(), whites = 0, j;
        if(i >= n)  return 0;
        if(dp[i][carpets] != -1)    return dp[i][carpets];

        if(floor[i] == '0')
            return dp[i][carpets] = getMinWhites(i+1, carpets, cLen, floor, dp);
        int add = 1e9;
        if(carpets > 0)
            add = getMinWhites(i+cLen, carpets-1, cLen, floor, dp);
        int noAdd = 1 + getMinWhites(i+1, carpets, cLen, floor, dp);
        return dp[i][carpets] = min(add, noAdd);
    }
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        // int n = floor.size();
        // vector<vector<int>> dp(n, vector<int>(numCarpets+1, -1));
        // return getMinWhites(0, numCarpets, carpetLen, floor, dp);

        int n = floor.size();
        vector<vector<int>> dp(n+carpetLen, vector<int>(numCarpets+1, 0));
        for(int i=n-1; i>=0; i--){
            for(int carpets=0; carpets<=numCarpets; carpets++){
                if(floor[i] == '0'){
                    dp[i][carpets] = dp[i+1][carpets];
                    continue;
                }

                int add = 1e9;
                if(carpets > 0)
                    add = dp[i+carpetLen][carpets-1];
                int noAdd = 1 + dp[i+1][carpets];
                dp[i][carpets] = min(add, noAdd);
            }
        }
        return dp[0][numCarpets];
    }
};