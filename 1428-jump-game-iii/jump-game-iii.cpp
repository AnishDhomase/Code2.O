class Solution {
    bool getCanReach(int i, vector<int>& arr, vector<int> &vis, vector<int> &dp){
        int n = arr.size();
        if(arr[i] == 0) return true;
        if(dp[i] != -1) return dp[i];

        if(vis[i] == 1)  return dp[i] = false;
        vis[i] = 1;

        if(i - arr[i] >= 0)
            if(getCanReach(i - arr[i], arr, vis, dp))
                return dp[i] = true;
        if(i + arr[i] < n)
            return dp[i] = getCanReach(i + arr[i], arr, vis, dp);
        return dp[i] = false;        
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n, 0), dp(n, -1);
        return getCanReach(start, arr, vis, dp);
    }
};