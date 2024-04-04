class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int minOps = 1e9;
        int n=nums.size(), i=0, j, l=0, r=0;
        for(j=n-1; j>=0; j--){
            r += nums[j];
            if(r >= x)  break;
        }
        if(r < x)   return -1;
        while(i<=j && j<n){
            if(l+r == x){
                minOps = min(minOps, i+n-j);
                l += nums[i];
                r -= nums[j];
                i++;
                j++;
            }
            else if(l+r < x){
                l += nums[i];
                i++;
            }
            else{
                r -= nums[j];
                j++;
            }
        }
        while(l+r<x && i<n){
            l += nums[i];
                i++;
        }
        if(l+r == x)
            minOps = min(minOps, i+n-j);
        if(minOps==1e9) return -1;
        return minOps;
        
    }
};