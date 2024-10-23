class Solution {
    bool getCanReach(int i, vector<int>& nums, vector<int> &dp){
        int n = nums.size();
        if(i == n-1)    return true;
        if(dp[i] != -1) return dp[i];

        int maxJump = nums[i];
        for(int jump = 1; jump <= maxJump; jump ++){
            if(i + jump >= n)   break;
            if(getCanReach(i + jump, nums, dp))
                return dp[i] = true;
        }
        return dp[i] = false;
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n, -1);
        // return getCanReach(0, nums, dp);
        vector<int> dp(n, 1);
        for(int i=n-2; i>=0; i--){
            int maxJump = nums[i];
            bool flag = true;
            for(int jump = 1; jump <= maxJump; jump ++){
                if(i + jump >= n)   break;
                if(dp[i + jump]){
                    dp[i] = true;
                    flag = false;
                    break;
                }
            }
            if(flag)    dp[i] = false;
        }
        return dp[0];
    }
};