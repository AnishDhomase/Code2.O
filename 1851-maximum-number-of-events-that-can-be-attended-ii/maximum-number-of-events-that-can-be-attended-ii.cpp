class Solution {
    int getNextPossibleEvent(int startInd, int prevEndDay, vector<vector<int>>& events){
        int n = events.size();
        int low = startInd, high = n - 1;
        int nextPossibleStart = n;
        while(low <= high){
            int mid = low + (high-low) / 2;
            int startDayOfEvent = events[mid][0];
            if(startDayOfEvent <= prevEndDay)
                low = mid + 1;
            else{
                nextPossibleStart = mid;
                high = mid - 1;
            }
        }
        return nextPossibleStart;
    }
    int getMaxVal(int i, int k, vector<vector<int>>& events, vector<vector<int>> &dp){
        int n = events.size();
        if(k == 0 || i == n)    return 0;
        if(dp[i][k] != -1)  return dp[i][k];

        // ignore event
        int dontdoIt = getMaxVal(i+1, k, events, dp);

        // do event
        int startDay = events[i][0], endDay = events[i][1], val = events[i][2];
        int nextEventInd = getNextPossibleEvent(i+1, endDay, events);
        int doIt = val + getMaxVal(nextEventInd, k-1, events, dp);

        return dp[i][k] = max(dontdoIt, doIt);
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        sort(events.begin(), events.end());
        return getMaxVal(0, k, events, dp);
    }
};