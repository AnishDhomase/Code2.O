typedef long long LL;
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        LL sum1, sum2, zeroCnt1, zeroCnt2;
        sum1 = sum2 = zeroCnt1 = zeroCnt2 = 0;
        for(int num: nums1){
            sum1 += num;
            if(num == 0)    zeroCnt1 ++;
        }
        for(int num: nums2){
            sum2 += num;
            if(num == 0)    zeroCnt2 ++;
        }
        if(zeroCnt1 == 0 && zeroCnt2 == 0)  return sum1 == sum2 ? sum1 : -1;
        LL minSumAfterReplacingZeroesIn1 = sum1 + zeroCnt1;
        LL minSumAfterReplacingZeroesIn2 = sum2 + zeroCnt2;
        if(zeroCnt1 == 0 && zeroCnt2 > 0)
            return minSumAfterReplacingZeroesIn1 < minSumAfterReplacingZeroesIn2 ? -1 : minSumAfterReplacingZeroesIn1;
        else if(zeroCnt2 == 0 && zeroCnt1 > 0)
            return minSumAfterReplacingZeroesIn2 < minSumAfterReplacingZeroesIn1 ? -1 : minSumAfterReplacingZeroesIn2;
        
        return max<LL>(minSumAfterReplacingZeroesIn1, minSumAfterReplacingZeroesIn2);
    }
};