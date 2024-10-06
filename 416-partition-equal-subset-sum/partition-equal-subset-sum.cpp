class Solution {
    bool isPossible(int i, int t, vector<int> &nums, vector<vector<int>> &dp){
        if(t==0)    return true;
        if(i==0)    return t == nums[0];
        if(dp[i][t] != -1)  return dp[i][t];
        bool notTake = isPossible(i-1, t, nums, dp);
        bool take = false;
        if(t-nums[i] >= 0)
            take = isPossible(i-1, t-nums[i], nums, dp);
        return dp[i][t] = take | notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total % 2 == 1)  return false;
        vector<vector<int>> dp(n, vector<int>(total/2+1, -1));
        return isPossible(n-1, total/2, nums, dp);
    }
};