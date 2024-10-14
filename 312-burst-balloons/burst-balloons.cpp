class Solution {
    int getMaxCoins(int i, int j, vector<int> &baloon, vector<vector<int>> &dp){
        if(i > j)   return 0;
        if(dp[i][j] != -1)  return dp[i][j];

        int maxC = 0;
        for(int b=i; b<=j; b++){
            int coins = baloon[i-1] * baloon[b] * baloon[j+1];
            coins += getMaxCoins(i, b-1, baloon, dp);
            coins += getMaxCoins(b+1, j, baloon, dp);
            maxC = max(maxC, coins);
        }
        return dp[i][j] = maxC;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        vector<int> baloon = {1};
        for(auto num : nums)    baloon.push_back(num);
        baloon.push_back(1);
        // return getMaxCoins(1, n, baloon, dp);

        for(int i=n; i>=1; i--){
            for(int j=i; j<=n; j++){
                int maxC = 0;
                for(int b=i; b<=j; b++){
                    int coins = baloon[i-1] * baloon[b] * baloon[j+1];
                    coins += dp[i][b-1];
                    coins += dp[b+1][j];
                    maxC = max(maxC, coins);
                }
                dp[i][j] = maxC;
            }
        }
        return dp[1][n];
    }
};