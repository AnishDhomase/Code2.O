class Solution {
    int fun(int i, int sum, int t, vector<int>& nums){
        if(i == nums.size()){
            if(sum == t)  return 1;
            return 0;
        }
        int p1 = fun(i+1, sum + nums[i], t, nums);
        int p2 = fun(i+1, sum - nums[i], t, nums);
        return p1 + p2;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return fun(0, 0, target, nums);
    }
};