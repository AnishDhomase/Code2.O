class Solution {
    int mod = 1e9 + 7;
    int getSeqCnt(int i, int lastDice, int consecutive, vector<int>& rollMax, vector<vector<vector<int>>> &dp){
        if(i == 0)  return 1;
        if(dp[i][lastDice][consecutive] != -1)
            return dp[i][lastDice][consecutive];

        int ways = 0;
        for(int dice = 0; dice <= 5; dice ++){
            if(dice != lastDice)
                ways = (ways + getSeqCnt(i-1, dice, 1, rollMax, dp)) % mod;
            else if(consecutive + 1 <= rollMax[lastDice])
                ways = (ways + getSeqCnt(i-1, lastDice, consecutive + 1, rollMax, dp)) % mod;
        }
        return dp[i][lastDice][consecutive] = ways;
    }
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(7, vector<int>(16, -1)));
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(7, vector<int>(16, 1)));
        vector<vector<int>> prev(7, vector<int>(16, 1));
        vector<vector<int>> curr(7, vector<int>(16, 1));
        // return getSeqCnt(n, 6, 0, rollMax, dp);
        for(int i=1; i<=n; i ++){
            for(int lastDice = 6; lastDice >= 0; lastDice --){
                for(int consecutive = 15; consecutive >= 0; consecutive --){
                    int ways = 0;
                    for(int dice = 0; dice <= 5; dice ++){
                        if(dice != lastDice)
                            ways = (ways + prev[dice][1]) % mod;
                        else if(consecutive + 1 <= rollMax[lastDice])
                            ways = (ways + prev[lastDice][consecutive + 1]) % mod;
                    }
                    curr[lastDice][consecutive] = ways;
                }   
            }
            prev = curr;
        }
        return prev[6][0];
    }
};