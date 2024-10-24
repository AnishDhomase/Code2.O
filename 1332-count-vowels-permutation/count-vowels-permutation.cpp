class Solution {
    int mod = 1e9 + 7;
    //a=1, e=2, i=3, o=4, u=5
    vector<int> getCharOptions(int prevChar){
        if(prevChar == 1) return {2};
        if(prevChar == 2) return {1, 3};
        if(prevChar == 3) return {1, 2, 4, 5};
        if(prevChar == 4) return {3, 5};
        if(prevChar == 5) return {1};
        return {1, 2, 3, 4, 5};
    }
    int getWays(int i, int prevChar, int n, vector<vector<int>> &dp){
        if(i == n+1)    return 1;
        if(dp[i][prevChar] != -1)   return dp[i][prevChar];

        int ways = 0;
        auto options = getCharOptions(prevChar);
        for(auto opt : options)
            ways = (ways + getWays(i+1, opt, n, dp)) % mod;
        return dp[i][prevChar] = ways;
    }
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n+2, vector<int>(6, 1));
        // return getWays(1, 0, n, dp);
        for(int i=n; i>=1; i--){
            for(int prevChar=0; prevChar <=5; prevChar ++){
                int ways = 0;
                auto options = getCharOptions(prevChar);
                for(auto opt : options)
                    ways = (ways + dp[i+1][opt]) % mod;
                dp[i][prevChar] = ways;
            }
        }
        return dp[1][0];
    }
};