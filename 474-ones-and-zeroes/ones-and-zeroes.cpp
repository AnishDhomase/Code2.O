class Solution {
    int getLargestSubset(int i, int zeroes, int ones, vector<vector<int>> &arr, int maxZ, int maxO, vector<vector<vector<int>>> &dp){
        int sz = arr.size();
        if(i == sz)  return 0;
        if(dp[i][zeroes][ones] != -1)   return dp[i][zeroes][ones];

        int take = 0;
        int newZ = zeroes + arr[i][0], newO = ones + arr[i][1];
        if(newZ <= maxZ && newO <= maxO)
            take = 1 + getLargestSubset(i+1, newZ, newO, arr, maxZ, maxO, dp);
        int notTake = 0 + getLargestSubset(i+1, zeroes, ones, arr, maxZ, maxO, dp);
        return dp[i][zeroes][ones] = max(take, notTake);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<vector<int>>> dp(sz, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        vector<vector<int>> arr;
        for(auto str : strs){
            int zeros = 0, ones = 0;
            for(auto ch : str){
                if(ch == '0')   zeros ++;
                else            ones ++;
            }
            arr.push_back({zeros, ones});
        }
        return getLargestSubset(0, 0, 0, arr, m, n, dp);
    }
};