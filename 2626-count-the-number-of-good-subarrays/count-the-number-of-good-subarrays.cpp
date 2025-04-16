typedef long long LL;
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int i = 0, j = 0, n = nums.size();
        LL totalPairs = 0, cntOfGoodSubArrays = 0;
        while(j < n){
            // remove old contribution of pairs of nums[i]
            totalPairs -= (LL) freq[nums[j]] * (freq[nums[j]] - 1) / 2;
            // add new contribution of pairs of nums[i]
            freq[nums[j]] ++;
            totalPairs += (LL) freq[nums[j]] * (freq[nums[j]] - 1) / 2;
            while(totalPairs >= k){
                cntOfGoodSubArrays += n - j;
                // remove old contribution of pairs of nums[i]
                totalPairs -= (LL) freq[nums[i]] * (freq[nums[i]] - 1) / 2;
                // add new contribution of pairs of nums[i]
                freq[nums[i]] --;
                totalPairs += (LL) freq[nums[i]] * (freq[nums[i]] - 1) / 2;
                i ++;
            }
            j++; 
        }
        return cntOfGoodSubArrays;
    }
};