class Solution {
    int mod = 1e9 + 7;
    int getWays(int i, string &corridor, vector<int> &dp){
        int n = corridor.size();
        if(i == n)  return 1;
        if(dp[i] != -1) return dp[i];

        long long ways = 0, seats = 0, partition;
        for(partition = i; partition < n; partition ++){
            if(corridor[partition] == 'S')  seats ++;
            if(seats == 2)   break;
        }
        int start = partition;
        for(++ partition; partition < n; partition ++)
            if(corridor[partition] == 'S')  break;
        
        int end = partition;
        int totalPartitions = end == n ? 1: end - start;
        if(seats == 2)
            ways = (long long) (ways + ((long long) totalPartitions * getWays(partition, corridor, dp)) % mod) % mod;
        return dp[i] = ways;
    }
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        int seats = 0;
        for(auto it : corridor)
            if(it == 'S')   seats ++;
        if(seats % 2)   return 0;
        if(seats == 2)  return 1;
        vector<int> dp(n, -1);
        return getWays(0, corridor, dp);
    }
};