class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> relativeVals;
        int prev = 0, n = nums.size();
        for(auto num: nums){
            relativeVals.push_back(num - prev);
            prev = num;
        }
        for(auto q: queries){
            int l = q[0];
            int r = q[1];
            relativeVals[l] --;
            if(r+1 < n) relativeVals[r+1] ++;
        }
        prev = 0;
        for(auto dX: relativeVals){
            int num = prev + dX;
            prev = num;
            if(num > 0) return false;
        }
        return true;
    }
};