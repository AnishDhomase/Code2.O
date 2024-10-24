class Solution {
    int getMaxScore(int i, int j, int prev, vector<int>& boxes, vector<vector<vector<int>>> &dp){
        if(i > j)   return pow(prev, 2);
        if(i == j)  return pow(prev+1, 2);
        if(dp[i][j][prev] != -1)    return dp[i][j][prev];

        int maxPoints = 0;
        int streakOf = boxes[i], streak = 1, p;
        for(p=i+1; p<=j; p++){
            if(boxes[p] != streakOf)    break;
            streak ++;
        }
        int remStart = p;
        int consider = pow(streak + prev, 2) + getMaxScore(remStart, j, 0, boxes, dp);
        maxPoints = max(maxPoints, consider);
        for( ; p<=j; p++){
            if(boxes[p] == streakOf){
                int notConsider = getMaxScore(p, j, prev + streak, boxes, dp) + getMaxScore(remStart, p-1, 0, boxes, dp);
                maxPoints = max(maxPoints, notConsider);
            }
        }
        return dp[i][j][prev] = maxPoints;
    }
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n+1, -1)));
        return getMaxScore(0, n-1, 0, boxes, dp); 
    }
};