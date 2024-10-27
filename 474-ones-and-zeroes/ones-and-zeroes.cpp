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
        // vector<vector<vector<int>>> dp(sz+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        vector<vector<int>> curr(m+1, vector<int>(n+1, 0)), next(m+1, vector<int>(n+1, 0));
        vector<vector<int>> arr;
        for(auto str : strs){
            int zeros = 0, ones = 0;
            for(auto ch : str){
                if(ch == '0')   zeros ++;
                else            ones ++;
            }
            arr.push_back({zeros, ones});
        }
        for(int i=sz-1; i>=0; i--){
            for(int zeroes=m; zeroes>=0; zeroes--){
                for(int ones=n; ones>=0; ones--){
                    int take = 0;
                    int newZ = zeroes + arr[i][0], newO = ones + arr[i][1];
                    if(newZ <= m && newO <= n)
                        take = 1 + next[newZ][newO];
                    int notTake = 0 + next[zeroes][ones];
                    curr[zeroes][ones] = max(take, notTake);
                }
            }
            next = curr;
        }
        return curr[0][0];
        // return getLargestSubset(0, 0, 0, arr, m, n, dp);
    }
};