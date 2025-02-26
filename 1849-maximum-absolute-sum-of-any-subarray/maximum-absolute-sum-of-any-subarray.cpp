class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = 0, highestSum = 0, lowestSum = 0;
        int maxAbsSum = 0;
        for(auto num: nums){
            sum += num;
            highestSum = max(highestSum, sum);
            lowestSum = min(lowestSum, sum);
            int sum1 = abs(sum-highestSum);
            int sum2 = abs(sum-lowestSum);
            maxAbsSum = max(maxAbsSum, max(sum1, sum2));
        }
        return maxAbsSum;
    }
};