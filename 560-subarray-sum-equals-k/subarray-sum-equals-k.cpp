class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ct = 0, n = nums.size(), i, sum;
        unordered_map<int,int> mp; //{sum,0/1}
        mp[0]++;
        for(i=0, sum = 0; i<n; i++){
            sum += nums[i];
            if(mp[sum-k])
                ct += mp[sum-k];
            mp[sum]++;
        }
        return ct;
    }
};