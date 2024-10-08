class Solution {
    int ways(int i, int amt, vector<int>& coins, vector<vector<int>> &dp){
        if(amt == 0)    return 1;
        if(i==0)    return amt % coins[0] == 0;
        if(dp[i][amt] != -1)    return dp[i][amt];

        int notPick, pick = 0;
        notPick = ways(i-1, amt, coins, dp);
        if(coins[i] <= amt) pick = ways(i, amt - coins[i], coins, dp);

        return dp[i][amt] = pick + notPick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return ways(n-1, amount, coins, dp);
    }
};