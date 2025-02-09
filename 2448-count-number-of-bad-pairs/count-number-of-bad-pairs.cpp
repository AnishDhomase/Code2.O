typedef long long LL;
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++)
            mp[nums[i]-i] ++;
        LL totalPairs = (LL) n * (n-1) / 2;
        for(auto it: mp){
            LL freq = it.second;
            LL goodPairs = (LL) freq * (freq-1) / 2;
            totalPairs -= goodPairs;
        }
        return totalPairs;
    }
};