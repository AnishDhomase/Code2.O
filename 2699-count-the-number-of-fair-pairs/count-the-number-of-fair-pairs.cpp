typedef long long LL;
class Solution {
    int getIndOfNumberJustGreaterThanOrEqual(int a, int from, vector<int>& nums){
        int n = nums.size();
        int low = from, high = n-1;
        int ind = n;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] < a)   low = mid + 1;
            else {
                ind = mid;
                high = mid - 1;
            }
        }
        return ind;
    }
    int getIndOfNumberJustSmallerThanOrEqual(int a, int from, vector<int>& nums){
        int n = nums.size();
        int low = from, high = n-1;
        int ind = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] > a)   high = mid - 1;
            else {
                ind = mid;
                low = mid + 1;
            }
        }
        return ind;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        LL cnt = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) {
            int start = getIndOfNumberJustGreaterThanOrEqual(lower-nums[i], i+1, nums);
            int end = getIndOfNumberJustSmallerThanOrEqual(upper-nums[i], i+1, nums);
            if(start <= end)
                cnt += (LL) end - start + 1;
        }
        return cnt;
    }
};