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
        // vector<vector<int>> dp(n, vector<int>(totalSum+1, -1));
        // return isPartitionPossible(0, 0, totalSum, nums, dp);

        vector<int> next(totalSum+1, -1), prev(totalSum+1);
        for(int subSetSum=totalSum; subSetSum>=0; subSetSum--)
            next[subSetSum] = subSetSum * 2 == totalSum;

        for(int i=n-1; i>=0; i--){
            for(int subSetSum=totalSum; subSetSum>=0; subSetSum--){
                // don't add to subSet
                if(next[subSetSum]){
                    prev[subSetSum] = true;
                    continue;
                }
                // add to subSet
                if(subSetSum + nums[i] <= totalSum)
                    prev[subSetSum] = next[subSetSum + nums[i]];
                else    prev[subSetSum] = false;
            }
            next = prev;
        }
        return prev[0];
    }
};