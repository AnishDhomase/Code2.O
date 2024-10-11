class Solution {
    int getLIS(int i, int prev, vector<int> &nums, vector<vector<int>> &dp){
        int n = nums.size();
        if(i < 0)   return 0;
        if(dp[i][prev] != -1)   return dp[i][prev];

        int pick = 0, notPick = 0;
        notPick = getLIS(i-1, prev, nums, dp);
        if(prev == n || nums[i] < nums[prev])
            pick = 1 + getLIS(i-1, i, nums, dp);
        
        return dp[i][prev] = max(notPick, pick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return getLIS(n-1, n, nums, dp);
    }
};