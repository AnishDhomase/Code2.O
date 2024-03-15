class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int indOdZero=-1, zeroes = 0, multiWithoutZeroes = 1;
        for(int i=0; i<n; i++){
            if(nums[i]==0){    
                zeroes++;
                indOdZero = i;
            }
            else        multiWithoutZeroes *= nums[i];
        }
        if(zeroes){
            if(zeroes==1)
                ans[indOdZero] = multiWithoutZeroes;
            return ans;
        }
        for(int i=0; i<n; i++)
            ans[i] = multiWithoutZeroes / nums[i];

        return ans;
    }
};