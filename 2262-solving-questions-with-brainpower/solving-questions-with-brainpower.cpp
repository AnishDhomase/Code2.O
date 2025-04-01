typedef long long LL;
class Solution {
    LL getMaxPoints(int i, vector<vector<int>>& questions, vector<LL> &dp){
        int n = questions.size();
        if(i >= n)  return 0;
        if(dp[i] != -1) return dp[i];

        // skip
        LL skipPoints = getMaxPoints(i+1, questions, dp);
        // solve
        int pointsBySolvingQues = questions[i][0], skipNext = questions[i][1];
        LL solvePoints = (LL) pointsBySolvingQues + getMaxPoints(i + skipNext + 1, questions, dp);

        return dp[i] = (LL) max<LL>(skipPoints, solvePoints);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<LL> dp(n, -1);
        LL ans = getMaxPoints(0, questions, dp);
        return ans;
    }
};