class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, vector<int>> mp;
        mp[0].push_back(-1);
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            mp[sum % k].push_back(i);
        }
        for(auto it : mp){
            auto arr = it.second;
            if(arr.size() >= 3)  return true;
            if(arr.size() < 2)  continue;
            if(arr[1] - arr[0] >= 2)    return true;
        }
        return false;
            
    }
};