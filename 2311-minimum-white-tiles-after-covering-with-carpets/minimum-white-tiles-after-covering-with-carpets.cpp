class Solution {
    int getMinWhites(int i, int carpets, int cLen, string &floor, vector<vector<int>> &dp){
        int n = floor.size(), whites = 0, j;
        if(carpets == 0){      
            for(int j=i; j<n; j++)
                if(floor[j] == '1') whites ++;
            return whites;
        }
        if(i >= n)  return 0;
        if(dp[i][carpets] != -1)    return dp[i][carpets];

        if(floor[i] == '0')
            return dp[i][carpets] = getMinWhites(i+1, carpets, cLen, floor, dp);
       
        int add = getMinWhites(i+cLen, carpets-1, cLen, floor, dp);
        int noAdd = 1 + getMinWhites(i+1, carpets, cLen, floor, dp);
        return dp[i][carpets] = min(add, noAdd);
    }
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        vector<vector<int>> dp(n, vector<int>(numCarpets+1, -1));
        return getMinWhites(0, numCarpets, carpetLen, floor, dp);
    }
};