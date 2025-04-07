class Solution {
    bool isPartitionPossible(int i, int subSetSum, int totalSum, vector<int>& nums, vector<vector<int>> &dp){
        int n = nums.size();
        if(i == n)  return subSetSum * 2 == totalSum;
        if(dp[i][subSetSum] != -1)  return dp[i][subSetSum];
        
        // don't add to subSet
        if(isPartitionPossible(i+1, subSetSum, totalSum, nums, dp))
            return dp[i][subSetSum] = true;
        // add to subSet
        return dp[i][subSetSum] = isPartitionPossible(i+1, subSetSum + nums[i], totalSum, nums, dp);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int>(totalSum+1, -1));

        return isPartitionPossible(0, 0, totalSum, nums, dp);
    }
};