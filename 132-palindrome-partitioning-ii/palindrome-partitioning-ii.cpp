class Solution {
    bool isPal(int start, int end, string &s){
        int n = s.length();
        int i = start, j=end;
        while(i<j){
            if(s[i] != s[j])
                return false;
            i ++;
            j --;
        }
        return true;
    }
    int getMinCuts(int i, string &s, vector<int> &dp){
        int n = s.length();
        if(i == n)   return 0;
        if(dp[i] != -1) return dp[i];

        int minCuts = 1e9;
        for(int p=i; p<n; p++){
            if(!isPal(i, p, s))    continue;
            int cuts = 1 + getMinCuts(p+1, s, dp);
            minCuts = min(minCuts, cuts);
        }
        return dp[i] = minCuts;
    }
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        // return getMinCuts(0, s, dp) - 1;
        for(int i=n-1; i>=0; i--){
            int minCuts = 1e9;
            for(int p=i; p<n; p++){
                if(!isPal(i, p, s))    continue;
                int cuts = 1 + dp[p+1];
                minCuts = min(minCuts, cuts);
            }
            dp[i] = minCuts;
        }
        return dp[0] - 1;
    }
};