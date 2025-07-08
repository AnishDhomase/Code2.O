class Solution {
    int getNextInd(int i, int endOfPrevEvent, vector<vector<int>>& events){
        int n = events.size();
        int low = i, high =  n - 1, nextInd = n;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(endOfPrevEvent < events[mid][0]){
                nextInd = mid;
                high = mid - 1;
            }
            else    low = mid + 1;
        } 
        return nextInd;
    }
    int getMaxValue(int i, int k, vector<vector<int>>& events, vector<vector<int>> &dp){
        int n = events.size();
        if(i == n || k == 0)  return 0;
        if(dp[i][k] != -1)  return dp[i][k];

        // don't attend
        int dontAttend = getMaxValue(i+1, k, events, dp);

        // attend
        int nextInd = getNextInd(i+1, events[i][1], events);
        int attend = events[i][2] + getMaxValue(nextInd, k-1, events, dp);
        return dp[i][k] = max(attend, dontAttend);
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        sort(events.begin(), events.end());
        return getMaxValue(0, k, events, dp);
    }
};