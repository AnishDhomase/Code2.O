class Solution {
    int mod = 1e9 + 7;
    bool isValid(int i, int len, string &s, int k){
        int n = s.length();
        if(i + len - 1 >= n)    return false;

        string currNumStr = s.substr(i, len);
        long num = stol(currNumStr);
        return num <= k;
    }
    int getWays(int i, string &s, int k, vector<int> &dp){
        int n = s.length();
        if(i == n)  return 1;
        if(dp[i] != -1) return dp[i];

        if(s[i] == '0') return 0;
        int ways = 0;
        for(int len = 1; isValid(i, len, s, k); len ++)
            ways = (ways + getWays(i+len, s, k, dp)) % mod;
        return dp[i] = ways;
    }
public:
    int numberOfArrays(string s, int k) { 
        int n = s.length();
        vector<int> dp(n, -1);
        return getWays(0, s, k, dp);
    }
};