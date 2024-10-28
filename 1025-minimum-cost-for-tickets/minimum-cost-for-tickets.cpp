class Solution {
    int getMinCost(int i, vector<int>& days, vector<int>& costs, vector<int> &dp){
        int n = days.size();
        if(i == n)  return 0;
        if(dp[i] != -1) return dp[i];

        // 1 day
        int buy1DayTicket = costs[0] + getMinCost(i+1, days, costs, dp);
        // 7 days
        int ticketValidUpto = days[i] + 6;
        int ub = upper_bound(days.begin(), days.end(), ticketValidUpto) - days.begin();
        int buy7DayTicket = costs[1] + getMinCost(ub, days, costs, dp);
        // 30 days
        ticketValidUpto = days[i] + 29;
        ub = upper_bound(days.begin(), days.end(), ticketValidUpto) - days.begin();
        int buy30DayTicket = costs[2] + getMinCost(ub, days, costs, dp);

        return dp[i] = min(buy1DayTicket, min(buy7DayTicket, buy30DayTicket));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1);
        return getMinCost(0, days, costs, dp);
    }
};