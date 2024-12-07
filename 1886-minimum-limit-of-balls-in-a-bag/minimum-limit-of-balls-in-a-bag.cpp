class Solution {
    bool isThisPenaltyPossible(int penalty, vector<int> &nums, int maxOperations){
        for(auto num : nums){
            int opsReq = ceil((double) num / penalty) - 1;
            if(maxOperations < opsReq)  return false;
            maxOperations -= opsReq;
        }
        return true;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1, h=*max_element(nums.begin(), nums.end());
        int ans;
        while(l <= h){
            int m = l + (h-l)/2;
            if(isThisPenaltyPossible(m, nums, maxOperations)){
                h = m - 1;
                ans = m;
            }
            else   l = m + 1;  
        }
        return ans;
    }
};