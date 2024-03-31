class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ct = 0;
        int n = nums.size(), minInd=-1, maxInd=-1, oobInd=-1;
        for(int i=0; i<n; i++){
            if(nums[i] == minK) minInd = i;
            if(nums[i] == maxK) maxInd = i;
            if(nums[i] < minK || maxK < nums[i])    oobInd = i;
            if(minInd != -1 && maxInd != -1){
                int low = min(minInd, maxInd);
                if(low - oobInd >= 0){
                    ct += low - oobInd;
                }
            }
        }
        return ct;

        // wrong
        // int n = nums.size();
        // long long ct = 0;
        // vector<int> mins, maxs, outs, minsmaxsouts={-1};
        // for(int i=0; i<n; i++){
        //     bool flag = false;
        //     if(nums[i]==minK){
        //         mins.push_back(i);
        //         flag = true;
        //     }
        //     if(nums[i]==maxK){
        //         maxs.push_back(i);
        //         flag = true;
        //     }
        //     if(minK > nums[i] || maxK < nums[i]){
        //         outs.push_back(i);
        //         flag = true;
        //     }
        //     if(flag)    minsmaxsouts.push_back(i);
        // }
        // outs.push_back(n);
        // int i=0, j=0;
        // while(i<mins.size() && j<maxs.size()){
        //     int low = min(mins[i], maxs[j]);
        //     int high = max(mins[i], maxs[j]);
        //     if(*(lower_bound(minsmaxsouts.begin(), minsmaxsouts.end(), low) + 1) == high || low==high){
        //         int l = minsmaxsouts[lower_bound(minsmaxsouts.begin(), minsmaxsouts.end(), low) - minsmaxsouts.begin() - 1];
        //         int h = *upper_bound(outs.begin(), outs.end(), high);
        //         ct += (long long) (low - l) * (h - high);
        //     }
        //     if(high == low){
        //         i++;
        //         j++;
        //         continue;
        //     }
        //     if(mins[i]==low)    i++;
        //     else                j++;
        // }
        // return ct;
    }
};