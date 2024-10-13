class Solution {
    int getMinCost(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
        if(i > j)  return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        int minC = 1e9;
        for(int cut = i; cut <= j; cut ++){
            int cost = cuts[j+1] - cuts[i-1] + getMinCost(i, cut-1, cuts, dp) + getMinCost(cut+1, j, cuts, dp);
            minC = min(minC, cost);
        }
        return dp[i][j] = minC;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();

        sort(cuts.begin(), cuts.end());
        vector<int> modCuts = {0};
        for(auto c : cuts)  modCuts.push_back(c);
        modCuts.push_back(n);

        vector<vector<int>> dp(m+1, vector<int>(m+1, -1));

        return getMinCost(1, m, modCuts, dp);
    }
};