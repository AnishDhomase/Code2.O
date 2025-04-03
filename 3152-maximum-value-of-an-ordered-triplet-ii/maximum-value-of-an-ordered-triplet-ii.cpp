typedef long long LL;
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        LL ans = 0;
        int n = nums.size();
        vector<int> greatestValToRight(n);
        vector<int> greatestValToLeft(n);
        for(int i=n-1, maxV=-1; i>=0; i--){
            greatestValToRight[i] = maxV;
            maxV = max(maxV, nums[i]);
        }
        for(int i=0, maxV=-1; i<n; i++){
            greatestValToLeft[i] = maxV;
            maxV = max(maxV, nums[i]);
        }
        for(int i=1; i<n-1; i++){
            LL calOfTriplet = (LL)(greatestValToLeft[i] - nums[i]) * greatestValToRight[i];
            ans = max<LL>(ans, calOfTriplet);
        }
        return ans;
    }
};