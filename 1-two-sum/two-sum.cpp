class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            int remaining = target - nums[i];
            bool isRemainingExists = mp.find(remaining) != mp.end();
            if(isRemainingExists) {
                int indexOfRemaining = mp[remaining];
                return {indexOfRemaining, i};
            }
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};