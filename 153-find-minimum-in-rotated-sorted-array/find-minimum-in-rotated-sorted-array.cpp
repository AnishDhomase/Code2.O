class Solution {
public:
    int findMin(vector<int>& nums) {
        int minVal = 1e9;
        int n = nums.size(), low = 0, high = n-1, mid;
        while(low <= high){
            mid = low + (high-low)/2;
            if(nums[low] <= nums[mid]){
                minVal = min(minVal,nums[low]);
                low = mid+1;
            }
            else{
                minVal = min(minVal,nums[mid]);
                high = mid-1;
            }
        }
        return minVal;
    }
};