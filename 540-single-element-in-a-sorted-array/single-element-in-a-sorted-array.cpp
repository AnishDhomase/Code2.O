class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size(), low=0, high=n-1, mid;
        if(n==1)    return nums[0];
        while(low < high){
            mid = low + (high-low)/2;
            if(mid%2 == 0){//even index
                if(nums[mid]==nums[mid+1])
                    low = mid+1;
                else 
                    high = mid;
            }
            else{//odd index
                if(nums[mid]==nums[mid-1])
                    low = mid+1;          
                else
                    high = mid; 
            }
        }
        return nums[low];
    }
};