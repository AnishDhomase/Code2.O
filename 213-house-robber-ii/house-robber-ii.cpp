class Solution {
    int fn(int i, vector<int>& nums, vector<int> &dp, bool lastTaken){
        if(i < 0)   return 0;
        if(i == 0){
            if(lastTaken)  return 0;
            return nums[0];
        }
        if(dp[i] != -1) return dp[i];
        int pick = nums[i] + fn(i-2, nums, dp, lastTaken);
        int notPick = fn(i-1, nums, dp, lastTaken);
        return dp[i] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1), dp1(n,-1);
        int lastTaken = nums[n-1] + fn(n-3, nums, dp, true);
        int lastNotTaken  = fn(n-2, nums, dp1, false);
        return max(lastTaken, lastNotTaken);
    }
};