class Solution {
    int fun(int i, int sum, vector<int> nums, vector<int> &dp){
        int n = nums.size();
        if(i>=n)
            return sum;
        if(dp[i] == -1){
            int p1 = fun(i+2, nums[i], nums, dp);
            int p2 = fun(i+1, 0, nums, dp);
            dp[i] = max(p1,p2);
            return sum + dp[i];
        }
        return sum + dp[i];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return fun(0, 0, nums, dp);
    }
};