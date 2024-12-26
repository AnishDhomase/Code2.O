class Solution {
    int getWays(int i, int sum, vector<int> &nums, int target, map<int,map<int,int>> &dp){
        int n = nums.size();
        if(i == n)  return sum == target;
        if(dp.find(i) != dp.end())
            if(dp[i].find(sum) != dp[i].end())  return dp[i][sum];
        
        // +
        int ways = getWays(i+1, sum + nums[i], nums, target, dp);
        // -
        ways += getWays(i+1, sum - nums[i], nums, target, dp);
        return dp[i][sum] = ways;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,map<int,int>> dp;
        return getWays(0, 0, nums, target, dp);
    }
};