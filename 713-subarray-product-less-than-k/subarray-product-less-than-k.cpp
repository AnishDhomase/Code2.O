class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ct=0, n = nums.size();
        for(int i=0; i<n; i++){
            int prod = 1;
            for(int j=i; j<n; j++){
                prod *= nums[j];
                if(prod < k)   ct++;
                else            break;
            }
        }
        return ct;
    }
};