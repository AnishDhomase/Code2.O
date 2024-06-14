class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=1, n=nums.size(), inc=0;
        while(i<n){
            if(nums[i-1] >= nums[i]){
                inc += nums[i-1] + 1 - nums[i];
                nums[i] = nums[i-1] + 1;
            }
            i++;
        }
        return inc;

    }
};