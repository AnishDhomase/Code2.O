class Solution {
    int getMax(int i, int taken, vector<int>& nums, int k, vector<vector<int>>& dp, vector<int> &subArrSums){
        int n = nums.size();
        if(taken == 3) return 0;
        if(i >= n)  return taken == 3 ? 0 : INT_MIN;
        if(i + (3-taken)*k > n)   return INT_MIN;
        if(dp[i][taken] != -1)  return dp[i][taken];
        
        // take
        int sum1 = subArrSums[i] + getMax(i+k, taken+1, nums, k, dp, subArrSums);
        // notTake
        int sum2 = getMax(i+1, taken, nums, k, dp, subArrSums);

        return dp[i][taken] = max(sum1, sum2);
    }
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        // presums
        vector<int> subArrSums(n-k+1), ans;
        int sum = 0;
        for(int i=0; i<k; i++)  sum += nums[i];
        subArrSums[0] = sum;
        for(int i=1; i+k<=n; i++){
            sum = sum - nums[i-1] + nums[i+k-1];
            subArrSums[i] = sum;
        }

        vector<vector<int>> dp(n, vector<int>(4, -1));
        int maxSum = getMax(0, 0, nums, k, dp, subArrSums);
        int i=0;
        while(ans.size() < 3 && i+k-1 < n){
            int remainingMaxSum = getMax(i+k, ans.size() + 1, nums, k, dp, subArrSums);
            if(subArrSums[i] + remainingMaxSum == maxSum){
                maxSum -= subArrSums[i];
                ans.push_back(i);
                i = i + k;
            }
            else    i ++;
        }
        return ans;
    }
};