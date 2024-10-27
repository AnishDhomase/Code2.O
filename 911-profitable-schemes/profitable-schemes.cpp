class Solution {
    int mod = 1e9 + 7;
    int getCntOfProfitableSchemes(int i, int prof, int people, int minProfit, vector<int>& group, vector<int>& profit, vector<vector<vector<int>>> &dp){
        int m = group.size();
        if(i == m)  return prof >= minProfit;
        if(dp[i][prof][people] != -1)   return dp[i][prof][people];

        long long ways = 0;
        // Do the crime
        if(people >= group[i]){
            int remainingPeople = people - group[i];
            int totalProf = prof + profit[i];
            ways = ((long long) ways + getCntOfProfitableSchemes(i+1, totalProf, remainingPeople, minProfit, group, profit, dp)) % mod;
        }
        // Skip this crime
        ways = ((long long) ways + getCntOfProfitableSchemes(i+1, prof, people, minProfit, group, profit, dp)) % mod;

        return dp[i][prof][people] = ways;
    }
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();
        int maxProf = accumulate(profit.begin(), profit.end(), 0);
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(maxProf+1, vector<int>(n+1, -1)));
        return getCntOfProfitableSchemes(0, 0, n, minProfit, group, profit, dp);
        // vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(maxProf+1, vector<int>(n+1, 0)));
    }   
};