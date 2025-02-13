typedef long long LL;
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int n = nums.size(), i;
        LL sum, maxSum = 0;
        for(i=0, sum=0; i<k; i++){
            freq[nums[i]] ++;
            sum = (LL) sum + nums[i];
        }  
        if(freq.size() == k)
            maxSum = max<LL>(maxSum, sum);
        while(i < n){
            freq[nums[i-k]] --;
            if(freq[nums[i-k]] == 0)    freq.erase(nums[i-k]);
            sum -= nums[i-k];
            freq[nums[i]] ++;
            sum = (LL) sum + nums[i];
            if(freq.size() == k)
                maxSum = max<LL>(maxSum, sum);
            i ++;
        }
        return maxSum;

    }
};