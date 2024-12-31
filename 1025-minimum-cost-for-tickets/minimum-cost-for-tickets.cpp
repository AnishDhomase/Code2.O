class Solution {
    int getMinCost(int i, vector<int>& days, vector<int>& costs, vector<int> &dp){
        int n = days.size();
        if(i == n)  return 0;
        if(dp[i] != -1) return dp[i];

        // get 1 day pass
        int pass1 = costs[0] + getMinCost(i+1, days, costs, dp);
        // get 7 day pass
        auto it = lower_bound(days.begin(), days.end(), days[i]+7);
        int nextDayindex = it - days.begin();
        int pass7 = costs[1] + getMinCost(nextDayindex, days, costs, dp);
        // get 30 day pass
        it = lower_bound(days.begin(), days.end(), days[i]+30); 
        nextDayindex = it - days.begin();
        int pass30 = costs[2] + getMinCost(nextDayindex, days, costs, dp);
        
        return dp[i] = min(pass1, min(pass7, pass30));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        // vector<int> dp(n, -1);
        // return getMinCost(0, days, costs, dp);
        vector<int> dp(n+1, 0);
        for(int i=n-1; i>=0; i--){
            // get 1 day pass
            int pass1 = costs[0] + dp[i+1];
            // get 7 day pass
            auto it = lower_bound(days.begin(), days.end(), days[i]+7);
            int nextDayindex = it - days.begin();
            int pass7 = costs[1] + dp[nextDayindex];
            // get 30 day pass
            it = lower_bound(days.begin(), days.end(), days[i]+30); 
            nextDayindex = it - days.begin();
            int pass30 = costs[2] + dp[nextDayindex];
            
            dp[i] = min(pass1, min(pass7, pass30));
        }
        return dp[0];
    }
};