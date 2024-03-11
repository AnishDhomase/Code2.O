class Solution {
    int lowerBound(vector<int> nums, int target){
        int first = -1;
        int n = nums.size(), low = 0, high = n-1, mid;
        while(low <= high){
            mid = (low + high) / 2;
            if(target == nums[mid]){
                first = mid;
                high = mid - 1;
            }
            else if(target < nums[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return first;
    }
    int upperBound(vector<int> nums, int target){
        int last = -1;
        int n = nums.size(), low = 0, high = n-1, mid;
        while(low <= high){
            mid = (low + high) / 2;
            if(target == nums[mid]){
                last = mid;
                low = mid + 1;
            }
            else if(target < nums[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return last;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;
        int n = nums.size(), low = 0, high = n-1, mid;
        vector<int> ans;
        ans.push_back(lowerBound(nums, target));
        ans.push_back(upperBound(nums, target));
        return ans;
        
    }
};