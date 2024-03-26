class Solution {
    pair<int,int> partitionsWithHighSubarrSum(int maxSubArrSum, vector<int> nums){
        int maxSum = 0, part=0;
        int subarrSum = 0;
        for(auto e : nums){
            if(subarrSum + e <= maxSubArrSum){
                subarrSum += e;
            }
            else{
                part++;
                maxSum = max(maxSum, subarrSum);
                subarrSum = e;
            }
        }
        maxSum = max(maxSum, subarrSum);
        return {part+1, maxSum};
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int maxSSum = high;
        while(low <= high){
            int mid = low + (high-low)/2;
            auto pr = partitionsWithHighSubarrSum(mid, nums);
            int numOfPartReq = pr.first, maxSubArrSum = pr.second;
            if(numOfPartReq <= k){
                high = mid-1;
                maxSSum = min(maxSSum, maxSubArrSum);
            }
            else
                low = mid+1;
        }
        return maxSSum;
    }
};