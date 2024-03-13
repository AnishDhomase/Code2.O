class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sumRanges = 0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            int minVal=1e9, maxVal=INT_MIN;
            for(int j=i; j<n; j++){
                minVal = min(minVal, nums[j]);
                maxVal = max(maxVal, nums[j]);
                sumRanges += maxVal - minVal;
            }
        }
        return sumRanges;
    }
};