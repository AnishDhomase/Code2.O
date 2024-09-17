class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0, r=0, maxL=0, n=nums.size(), z=0;
        queue<int> Q;
        while(r<n){
            if(nums[r] == 1){
                maxL = max(maxL, r-l+1);
                r ++;
            }
            else {
                z ++;
                r ++;
                if(z > k){
                    while(nums[l] != 0)   l++;
                    l ++;
                    z --;
                }
            }
            maxL = max(maxL, r-l);
        }
        return maxL;
    }
};