class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for(auto v: grid)
            for(auto num: v)
                nums.push_back(num);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int middle = n/2, reducedTo = nums[middle];
        int minOps = 0;
        for(auto num: nums){
            int diff = abs(num-reducedTo);
            if(diff % x != 0)
                return -1;
            minOps += diff/x;
        }
        return minOps;
    }
};