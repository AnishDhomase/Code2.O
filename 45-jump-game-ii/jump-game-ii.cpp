class Solution {
    int getMinJumps(int i, vector<int>& nums, vector<int> &dp){
        int n = nums.size();
        if(i == n-1)  return 0;
        if(dp[i] != -1) return dp[i];

        int maxJump = nums[i], minJumps = 1e9;
        for(int jump=1; jump<=maxJump; jump++){
            if(i + jump >= n)   break;
            int jumpCnt = 1 + getMinJumps(i + jump, nums, dp);
            minJumps = min(minJumps, jumpCnt);
        }
        return dp[i] = minJumps;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return getMinJumps(0, nums, dp);
    }
};