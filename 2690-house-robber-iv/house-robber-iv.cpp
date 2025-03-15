class Solution {
    int getRobbedHousesCnt(int i, int capacity, vector<int> &nums, vector<int> &dp){
        int n = nums.size();
        if(i >= n)  return 0;
        if(dp[i] != -1) return dp[i];

        int rob = 0;
        // rob
        if(capacity >= nums[i])
            rob = 1 + getRobbedHousesCnt(i+2, capacity, nums, dp);
        // don't rob
        int dontRob = getRobbedHousesCnt(i+1, capacity, nums, dp);

        return dp[i] = max(rob, dontRob);
    }
    bool isKRobberiesPossibleWithThisCapacity(int capacity, vector<int> &nums, int k){
        int n = nums.size();
        vector<int> dp(n, -1);

        int cntRobbedHouses = getRobbedHousesCnt(0, capacity, nums, dp);
        return k <= cntRobbedHouses;
    }
public:
    int minCapability(vector<int> &nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int ans;
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(isKRobberiesPossibleWithThisCapacity(mid, nums, k)){
                ans = mid;
                high = mid - 1;
            }
            else    low = mid + 1;
        }
        return ans;
    }
};