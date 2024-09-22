class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0, r=0, n=nums.size(), z=0, maxL = 0;
        while(r<n){
            if(nums[r] == 0)
                z ++;
            if(z <= k)
                maxL = max(maxL, r-l+1);
            else{
                if(nums[l] == 0)    z--;
                l++;
            }
            r++;
        }
        return maxL;
    }
};