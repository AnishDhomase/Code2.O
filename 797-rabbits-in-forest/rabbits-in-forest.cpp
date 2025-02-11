class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int minRabits = 0;
        unordered_map<int,int> mp;
        for(auto a: answers)    mp[a] ++;
        for(auto it: mp){
            int ans = it.first, freq = it.second;
            minRabits +=  (ans+1) * ceil((double) freq / (ans+1));
        }
        return minRabits;
    }
};