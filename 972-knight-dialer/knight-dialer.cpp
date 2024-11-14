typedef long long LL;
class Solution {
    bool isValidAdjCell(int x, int y){
        if(y == 3 && (x == 0 || x == 2))
            return false;
        return x >=0 && x < 3 && y >=0 && y < 4;
    }
    int mod = 1e9 + 7;
    int getWays(int len, int x, int y, vector<vector<vector<int>>> &dp){
        if(len == 1)    return 1;
        if(dp[len][x][y] != -1) return dp[len][x][y];

        vector<int> dX = {-2, -2, 2, 2, 1, -1, 1, -1};
        vector<int> dY = {1, -1, 1, -1, -2, -2, 2, 2};
        LL ways = 0;
        for(int i=0; i<8; i++){
            int adjX = x  + dX[i];
            int adjY = y  + dY[i];
            if(isValidAdjCell(adjX, adjY))
                ways = ((LL) ways + getWays(len-1, adjX, adjY, dp)) % mod;         
        }
        return dp[len][x][y] = ways;
    }
public:
    int knightDialer(int n) {
        LL ways = 0;
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (3, vector<int> (4, -1)));
        // for(int x=0; x<3; x++){
        //     for(int y=0; y<4; y++){
        //         if(isValidAdjCell(x, y))
        //             ways = ((LL) ways + getWays(n, x, y, dp)) % mod;   
        //     }
        // }
        // return ways;

        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (3, vector<int> (4, 1)));
        vector<vector<int>> prev(3, vector<int> (4, 1)), curr(3, vector<int> (4, 1));
        vector<int> dX = {-2, -2, 2, 2, 1, -1, 1, -1};
        vector<int> dY = {1, -1, 1, -1, -2, -2, 2, 2};
        for(int len=2; len<=n; len++){
            for(int x=0; x<3; x++){
                for(int y=0; y<4; y++){
                    LL ways = 0;
                    if(!isValidAdjCell(x, y)) continue;
                    for(int i=0; i<8; i++){
                        int adjX = x  + dX[i];
                        int adjY = y  + dY[i];
                        if(isValidAdjCell(adjX, adjY))
                            ways = ((LL) ways + prev[adjX][adjY]) % mod;         
                    }
                    curr[x][y] = ways;
                }
            }
            prev = curr;
        }
        for(int x=0; x<3; x++){
            for(int y=0; y<4; y++)
                if(isValidAdjCell(x, y))
                    ways = ((LL) ways + curr[x][y]) % mod;     
        }
        return ways;
        
        
    }
};