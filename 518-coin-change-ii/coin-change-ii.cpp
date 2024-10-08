class Solution {
    int ways(int i, int amt, vector<int>& coins, vector<vector<long long>> &dp){
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
        vector<long long> prev(amount+1), curr(amount+1, 1);
        // return ways(n-1, amount, coins, dp);
        // for(int i=0; i<n; i++)  
        //     dp[i][0] = 1;
        for(int amt=0; amt<=amount; amt++)  
            prev[amt] = amt % coins[0] == 0;

        for(int i=1; i<n; i++){
            for(int amt=1; amt<=amount; amt++){
                int notPick, pick = 0;
                notPick = prev[amt];
                if(coins[i] <= amt) pick = prev[amt - coins[i]];
                prev[amt] = (long long) pick + (long long) notPick;
            }

        }
        return prev[amount];
    }
};