class Solution {
    int getMaxCoeff(int i, int time, vector<int>& satisfaction, vector<vector<int>> &dp){
        int n = satisfaction.size();
        if(i == n)  return 0;
        if(dp[i][time] != -1)   return dp[i][time];

        int prepare = satisfaction[i] * (time + 1) + getMaxCoeff(i+1, time + 1, satisfaction, dp);
        int notPrepare = getMaxCoeff(i+1, time, satisfaction, dp);

        return dp[i][time] = max(prepare, notPrepare);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return getMaxCoeff(0, 0, satisfaction, dp);
    }
};