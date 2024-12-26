class Solution {
    int getWays(int i, int sum, vector<int> &nums, int target){
        int n = nums.size();
        if(i == n)  return sum == target;
        // +
        int ways = getWays(i+1, sum + nums[i], nums, target);
        // -
        ways += getWays(i+1, sum - nums[i], nums, target);
        return ways;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return getWays(0, 0, nums, target);
    }
};