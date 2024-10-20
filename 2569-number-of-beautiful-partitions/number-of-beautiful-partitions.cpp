class Solution {
    int mod = 1e9 + 7;
    bool isPrimeDigit(int i, string &s){
        return s[i] == '2' || s[i] == '3' || s[i] == '5' || s[i] == '7';
    }
    int getWways(int i, int p, string &s, int k, int minLength, vector<vector<int>> &dp){
        int n = s.length();
        if(i == n)   return p == k;
        if(p == k)   return i == n;
        if(dp[i][p] != -1)  return dp[i][p];

        int ways = 0;
        if(!isPrimeDigit(i, s))  return 0;
        for(int j = i+1; j < n; j ++){
            if(!isPrimeDigit(j, s) && j-i+1 >= minLength)
                ways = (ways + getWways(j+1, p+1, s, k, minLength, dp))  % mod;       
        }
        return dp[i][p] = ways;
    }
public:
    int beautifulPartitions(string s, int k, int minLength) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return getWways(0, 0, s, k, minLength, dp);
    }
};