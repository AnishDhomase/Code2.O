class Solution {
    bool isValid2CharNumber(int i, string &s){
        string num = s.substr(i, 2);
        if(num[0] == '0')   return false;
        int n = stoi(num);
        return n <= 26; 
    }
    bool isValidCharNumber(int i, string &s){
        string num = s.substr(i, 1);
        int n = stoi(num);
        return 0 != n; 
    }
    int getWays(int i, string &s, vector<int> &dp){
        int n = s.length();
        if(i == n)  return 1;
        if(dp[i] != -1) return dp[i];

        int ways = 0;
        if(isValidCharNumber(i, s))
            ways += getWays(i+1, s, dp);
        if(i <= n-2 && isValid2CharNumber(i, s))
            ways += getWays(i+2, s, dp);
        
        return dp[i] = ways;
    }
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        return getWays(0, s, dp);
    }
};