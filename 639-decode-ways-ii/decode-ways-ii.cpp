class Solution {
    int mod = 1e9 + 7;
    bool isValid2CharNumber(string &num){
        if(num[0] == '0')   return false;
        int n = stoi(num);
        return n <= 26; 
    }
    bool isValidCharNumber(int i, string &s){
        string num = s.substr(i, 1);
        int n = stoi(num);
        return 0 != n; 
    }
    int getMultiplier(string &s){
        int multiplier = 0;
        if(s[0] == s[1] && s[0] == '*')
            multiplier = 15;  
        else if(s[0] == '*'){
            multiplier = 1;
            if(s[1] <= '6') multiplier ++;
        }
        else if(s[1] == '*'){
            if(s[0] == '1') multiplier = 9;
            else if(s[0] == '2') multiplier = 6;
        }
        else{
            if(isValid2CharNumber(s))
                multiplier = 1;
        }
        return multiplier;
    }
    int getWays(int i, string &s, vector<int> &dp){
        int n = s.length();
        if(i == n)  return 1;
        if(dp[i] != -1) return dp[i];

        long long ways = 0;
        if(s[i] == '*' || isValidCharNumber(i, s)){
            int multiplier = 1;
            if(s[i] == '*') multiplier = 9;
            ways = (long long) (ways + ((long long)multiplier * getWays(i+1, s, dp)) % mod) % mod;
        }
        if(i <= n-2){
            string str = s.substr(i, 2);
            int multiplier = getMultiplier(str);
            if(multiplier != 0)
                ways = (long long) (ways + ((long long)multiplier * getWays(i+2, s, dp)) % mod) % mod;
        }
        return dp[i] = ways;
    }
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1, 1);
        // return getWays(0, s, dp);
        for(int i=n-1; i>=0; i--){
            long long ways = 0;
            if(s[i] == '*' || isValidCharNumber(i, s)){
                int multiplier = 1;
                if(s[i] == '*') multiplier = 9;
                ways = (long long) (ways + ((long long)multiplier * dp[i+1]) % mod) % mod;
            }
            if(i <= n-2){
                string str = s.substr(i, 2);
                int multiplier = getMultiplier(str);
                if(multiplier != 0)
                    ways = (long long) (ways + ((long long)multiplier * dp[i+2]) % mod) % mod;
            }
            dp[i] = ways;
        }
        return dp[0];
    }
};
