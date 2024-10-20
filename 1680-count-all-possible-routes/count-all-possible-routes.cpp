class Solution {
    int mod = 1e9 + 7;
    int getWays(int i, int fuel, vector<int> &locations, int finish, vector<vector<int>> &dp){
        if(dp[i][fuel] != -1)   return dp[i][fuel];
        
        int n = locations.size();
        int ways = i == finish ? 1 : 0;
        for(int nextCity = 0; nextCity < n; nextCity ++){
            if(nextCity == i)   continue;
            int fuelReq = abs(locations[i] - locations[nextCity]);
            if(fuel >= fuelReq)
            ways = (ways + getWays(nextCity, fuel-fuelReq, locations, finish, dp)) % mod;
        }
        return dp[i][fuel] = ways;
    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(fuel+1, -1));
        return getWays(start, fuel, locations, finish, dp);
    }
};