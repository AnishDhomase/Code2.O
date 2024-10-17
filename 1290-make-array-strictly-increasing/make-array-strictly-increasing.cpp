class Solution {
    int getMinOps(int i, int prevInd, vector<int>& arr1, vector<int>& arr2, vector<vector<int>> &dp){
        int n = arr1.size(), m = arr2.size();
        if(i == n)  return 0;
        if(dp[i][prevInd+2] != -1)  return dp[i][prevInd+2];

        int minOps = 1e9, ops;
        int prevVal = INT_MIN;
        if(prevInd == -1)   prevVal = arr1[i-1];
        if(prevInd >= 0)    prevVal = arr2[prevInd];

        if(arr1[i] > prevVal){
            ops = 0 + getMinOps(i+1, -1, arr1, arr2, dp);
            minOps = min(minOps, ops);
        }

        int ub = upper_bound(arr2.begin(), arr2.end(), prevVal) - arr2.begin();
        if(ub != m){
            ops = 1 + getMinOps(i+1, ub, arr1, arr2, dp);
            minOps = min(minOps, ops);
        }
        return dp[i][prevInd+2] = minOps;
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        vector<vector<int>> dp(n, vector<int>(m+2, -1));
        unordered_set<int> st(arr2.begin(), arr2.end());
        vector<int> arr(st.begin(), st.end());
        sort(arr.begin(), arr.end());

        int minOps =  getMinOps(0, -2, arr1, arr, dp);
        return minOps == 1e9 ? -1 : minOps;
    }
};