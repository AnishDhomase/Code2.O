class Solution {
    int getMaxWiggleSeq(int i, int prevInd, int prevDiff, vector<int>& nums, vector<vector<vector<int>>> &dp){
        int n = nums.size();
        if(i == n)  return 0;
        if(dp[i][prevInd][prevDiff] != -1)  return dp[i][prevInd][prevDiff];

        int take = 0, notTake = 0;
        if(prevInd == n){
            take = 1 + getMaxWiggleSeq(i+1, i, prevDiff, nums, dp);
        }
        else if(prevDiff == 0){
            int diff = nums[i] - nums[prevInd] < 0 ? 2 : 1;
            if(nums[i] != nums[prevInd])    
                take = 1 + getMaxWiggleSeq(i+1, i, diff, nums, dp);
        }
        else{
            int diff = nums[i] - nums[prevInd] < 0 ? 2 : 1;
            if(diff != prevDiff && nums[i] != nums[prevInd])
                take = 1 + getMaxWiggleSeq(i+1, i, diff, nums, dp);
        }
        notTake = getMaxWiggleSeq(i+1, prevInd, prevDiff, nums, dp);
        return dp[i][prevInd][prevDiff] = max(take, notTake);
    }
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n+1, vector<int>(3, -1)));
        return getMaxWiggleSeq(0, n, 0, nums, dp);
    }
};