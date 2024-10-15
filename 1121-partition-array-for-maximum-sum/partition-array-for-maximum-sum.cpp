class Solution {
    int getMaxVal(int i, vector<int>& arr, int k, vector<int> &dp){
        int n = arr.size();
        if(i == n)  return 0;
        if(dp[i] != -1) return dp[i];

        int maxE = INT_MIN, maxV = INT_MIN;
        for(int p=i; p<i+k && p<n; p++){
            maxE = max(maxE, arr[p]);
            int val = (p-i+1) * maxE + getMaxVal(p+1, arr, k, dp);
            maxV = max(maxV, val);
        }
        return dp[i] = maxV;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return getMaxVal(0, arr, k, dp);
    }
};