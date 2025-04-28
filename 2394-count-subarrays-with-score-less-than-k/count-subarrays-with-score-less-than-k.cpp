typedef long long LL;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        LL cntOfSubarraysWithScoreGreaterThanOrEqualToK = 0;
        int i, j, n = nums.size();
        LL sum, totalNumOfSubarraysPossible = (LL) n * (n+1) / 2;
        sum = i = j = 0;
        while(j < n) {
            sum += nums[j];
            while(sum * (j-i+1) >= k){
                cntOfSubarraysWithScoreGreaterThanOrEqualToK += n - j;
                sum -= nums[i]; 
                i ++;
            }
            j ++;
        }
        LL cntOfSubarraysWithScoreSmallerThanK = totalNumOfSubarraysPossible - cntOfSubarraysWithScoreGreaterThanOrEqualToK;
        return cntOfSubarraysWithScoreSmallerThanK;


         
    }
};