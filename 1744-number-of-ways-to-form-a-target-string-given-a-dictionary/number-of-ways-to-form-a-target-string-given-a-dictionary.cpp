typedef long long LL;
int mod = 1e9 + 7;
class Solution {
    int getWays(int i, int k, vector<vector<int>> &freqMap, string target, vector<vector<int>> &dp){
        int n = target.size(), m = freqMap.size();
        if(i == n)  return 1;
        if(k == m)  return 0;
        if(m-k < n-i)   return 0; 
        if(dp[i][k] != -1)  return dp[i][k];

        // skip
        LL ways = ((LL) getWays(i, k+1, freqMap, target, dp)) % mod;
        // take
        int cnt = freqMap[k][target[i]-'a'];
        if(cnt > 0){         
            ways = ((LL)ways + ((LL)cnt * getWays(i+1, k+1, freqMap, target, dp)) % mod) % mod;
        }
        return dp[i][k] = ways;    
    }
public:
    int numWays(vector<string>& words, string target) {
        int n = target.length(), m = words[0].length(), sz = words.size();
        vector<vector<int>> freqMap(m, vector<int>(26, 0));
        for(auto word: words){
            for(int j=0; j<m; j++)
                freqMap[j][word[j]-'a'] ++;
        }
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return getWays(0, 0, freqMap, target, dp);
    }
};