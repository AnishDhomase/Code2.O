class Solution {
    int getCntOfMaxOrSubsets(int i, int subsetOr, int maxOr, vector<int>& nums){
        int n = nums.size();
        if(i == n) return subsetOr == maxOr;
        
        // take
        int takeCnt = getCntOfMaxOrSubsets(i+1, subsetOr | nums[i], maxOr, nums);
        // notTake
        int notTakeCnt = getCntOfMaxOrSubsets(i+1, subsetOr, maxOr, nums);
        return takeCnt + notTakeCnt;

    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(auto num: nums) maxOr |= num;
        return getCntOfMaxOrSubsets(0, 0, maxOr, nums);
    }
};