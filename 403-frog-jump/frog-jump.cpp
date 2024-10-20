class Solution {
    bool getCanJump(int i, int prevJump, vector<int> &stones, vector<vector<int>> &dp){
        int n = stones.size();
        if(i == n-1) return true;
        if(dp[i][prevJump] != -1)    return dp[i][prevJump];

        for(int next = i+1; next < n; next ++){
            int reqJump = stones[next] - stones[i];
            if(reqJump < prevJump - 1)  continue;
            if(reqJump > prevJump + 1)  break;
            if(getCanJump(next, reqJump, stones, dp))
                return dp[i][prevJump] = true;
        }
        return dp[i][prevJump] = false;
    }
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size(), maxJump = n-1;

        vector<vector<int>> dp(n, vector<int>(maxJump, -1));
        return getCanJump(0, 0, stones, dp);
    }
};