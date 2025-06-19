class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int cnt = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        while(j<n){
            if(nums[j] - nums[i] <= k){
                j++;
                continue;
            }
            i = j;  
            cnt ++;
        }
        return cnt + 1;
    }
};