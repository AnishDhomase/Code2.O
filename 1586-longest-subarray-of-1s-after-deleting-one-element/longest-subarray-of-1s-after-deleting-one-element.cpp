class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0, j=0, n=nums.size(), maxL=-1, del = 1;
        while(j<n){
            if(nums[j] == 0)    del --;
            while(del < 0){
                if(nums[i] == 0)    del ++;
                i ++;
            }
            maxL = max(maxL, j-i+1);
            j ++;
        }
        return maxL == -1 ? 0 : maxL - 1;
    }
};