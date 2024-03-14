class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size(), low=1, high=n-2, mid;
        if(n==1)    return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-2]<nums[n-1]) return n-1;
        while(low <= high){
            mid = low + (high-low)/2;
            if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1])
                return mid;
            if(nums[mid-1] > nums[mid])
                high = mid-1;
            else
                low = mid+1;
        }
        return -1;
    }
};