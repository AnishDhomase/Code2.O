class Solution {
    int AnsForGoalZero(vector<int> onesInd, int n){
        int numSubarr = 0;
        int sz1 = onesInd.size();
        
        for(int i=0; i<=sz1; i++){
            if(i==0){
                int l = onesInd[i];
                numSubarr += l*(l+1)/2;
            }
            else if(i==sz1){
                int l = n - onesInd[i-1] - 1;
                numSubarr += l*(l+1)/2;
            }
            else{
                int l = onesInd[i] - onesInd[i-1] - 1;
                numSubarr += l*(l+1)/2;
            }
        }
        return numSubarr;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int numSubarr = 0;
        int n = nums.size();
        vector<int> onesInd;
        for(int i=0; i<n; i++){
            if(nums[i]==1)
                onesInd.push_back(i);
        }
        int sz1 = onesInd.size();
        if(goal == 0){
            if(sz1 == 0)    return n*(n+1)/2;
            return AnsForGoalZero(onesInd, n);
        }
        for(int i=0, j=goal-1; j<sz1; i++,j++){
            int indOfOne_iAtNums = onesInd[i], indOfOne_jAtNums = onesInd[j];
            int indFirst_Left1to_iAtNums,  indFirst_Right1to_jAtNums;
            if(i==0)    indFirst_Left1to_iAtNums = -1;
            else        indFirst_Left1to_iAtNums = onesInd[i-1];
            if(j==sz1-1)  indFirst_Right1to_jAtNums = n;
            else        indFirst_Right1to_jAtNums = onesInd[j+1];
            int l = (indOfOne_iAtNums - indFirst_Left1to_iAtNums);
            int r = (indFirst_Right1to_jAtNums - indOfOne_jAtNums);
            numSubarr += (l * r);
        }
        return numSubarr;
    }
};