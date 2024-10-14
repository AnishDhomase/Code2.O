class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> len(n, 1), src(n);
        for(int i=0; i<n; i++){
            src[i] = i;
            for(int j=0; j<i; j++){
                if(nums[i] % nums[j] == 0 && len[j] + 1 > len[i]){
                    len[i] = len[j] + 1;
                    src[i] = j;
                }
            }
        }
        int maxLen = 0, lastInd = -1;
        for(int i=0; i<n; i++){
            if(len[i] > maxLen){
                maxLen = len[i];
                lastInd = i;
            }
        }
        vector<int> ans = {nums[lastInd]};
        while(src[lastInd] != lastInd){
            lastInd = src[lastInd];
            ans.push_back(nums[lastInd]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};