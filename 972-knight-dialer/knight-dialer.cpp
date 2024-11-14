typedef long long LL;
class Solution {
    bool isValidAdjCell(int x, int y){
        if(y == 3 && (x == 0 || x == 2))
            return false;
        return x >=0 && x < 3 && y >=0 && y < 4;
    }
    int mod = 1e9 + 7;
    int getWays(int x, int y, int len, vector<vector<vector<int>>> &dp){
        if(len == 1)    return 1;
        if(dp[x][y][len] != -1) return dp[x][y][len];

        vector<int> dX = {-2, -2, 2, 2, 1, -1, 1, -1};
        vector<int> dY = {1, -1, 1, -1, -2, -2, 2, 2};
        LL ways = 0;
        for(int i=0; i<8; i++){
            int adjX = x  + dX[i];
            int adjY = y  + dY[i];
            if(isValidAdjCell(adjX, adjY))
                ways = ((LL) ways + getWays(adjX, adjY, len-1, dp)) % mod;         
        }
        return dp[x][y][len] = ways;
    }
public:
    int knightDialer(int n) {
        LL ways = 0;
        vector<vector<vector<int>>> dp(3, vector<vector<int>> (4, vector<int> (n+1, -1)));
        for(int x=0; x<3; x++){
            for(int y=0; y<4; y++){
                if(isValidAdjCell(x, y))
                    ways = ((LL) ways + getWays(x, y, n, dp)) % mod;   
            }
        }
        return ways;
    }
};