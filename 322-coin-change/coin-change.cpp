class Solution {
    int fn(int amt, vector<int>& coins, vector<int>& dp){
        if(amt == 0)  return 0;
        if(dp[amt] != -1)   return dp[amt];
        int minCoins = 1e9;
        for(auto coin : coins){
            if(amt - coin >= 0){
                int c = fn(amt - coin, coins, dp);
                minCoins = min(minCoins, c);
            }
            else    break;
        }
        return dp[amt] = minCoins == 1e9 ? 1e9 : minCoins + 1;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        sort(coins.begin(), coins.end());
        int minCoins =  fn(amount, coins, dp);
        return minCoins == 1e9 ? -1 : minCoins;
    }
};