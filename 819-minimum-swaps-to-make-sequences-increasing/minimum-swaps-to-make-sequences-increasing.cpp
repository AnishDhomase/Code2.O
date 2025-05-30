class Solution {
    bool isNoSwapPossible(int i, int prev1, int prev2, vector<int> &nums1, vector<int> &nums2){
        if(i == 0)  return true;
        int prevElem1, prevElem2;
        int n = nums1.size();

        if(prev1 == 1)  prevElem1 = nums1[i-1];
        else            prevElem1 = nums2[i-1];
        if(prev2 == 1)  prevElem2 = nums1[i-1];
        else            prevElem2 = nums2[i-1];
        
        if(nums1[i] > prevElem1 && nums2[i] > prevElem2)   return true;
        return false;
    }
    bool isSwapPossible(int i, int prev1, int prev2, vector<int> &nums1, vector<int> &nums2){
        if(i == 0)  return true;
        int prevElem1, prevElem2;
        int n = nums1.size();

        if(prev1 == 1)  prevElem1 = nums1[i-1];
        else            prevElem1 = nums2[i-1];
        if(prev2 == 1)  prevElem2 = nums1[i-1];
        else            prevElem2 = nums2[i-1];
        
        if(nums2[i] > prevElem1 && nums1[i] > prevElem2)   return true;
        return false;
    }
    int getMinSwaps(int i, int prev1, int prev2, vector<int>& nums1, vector<int>& nums2, vector<vector<vector<int>>> &dp){
        int n = nums1.size();
        if(i == n)  return 0;
        if(dp[i][prev1][prev2] != -1) return dp[i][prev1][prev2];
        
        int doSwap = 1e9, doNoSwap = 1e9;
        if(isNoSwapPossible(i, prev1, prev2, nums1, nums2))
            doNoSwap = 0 + getMinSwaps(i+1, 1, 2, nums1, nums2, dp);

        if(isSwapPossible(i, prev1, prev2, nums1, nums2))
            doSwap = 1 + getMinSwaps(i+1, 2, 1, nums1, nums2, dp);

        return dp[i][prev1][prev2] = min(doSwap, doNoSwap);
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // int n = nums1.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(3, -1)));
        // return getMinSwaps(0, 0, 0, nums1, nums2, dp);
        int n = nums1.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(3, 0)));
        vector<vector<int>> next(3, vector<int>(3, 0)), curr(3, vector<int>(3, 0));
        for(int i=n-1; i>=0; i--){
            for(int prev1=0; prev1 <=2; prev1++){
                for(int prev2=0; prev2 <=2; prev2++){
                    int doSwap = 1e9, doNoSwap = 1e9;
                    if(isNoSwapPossible(i, prev1, prev2, nums1, nums2))
                        doNoSwap = 0 + next[1][2];

                    if(isSwapPossible(i, prev1, prev2, nums1, nums2))
                        doSwap = 1 + next[2][1];

                    curr[prev1][prev2] = min(doSwap, doNoSwap);
                }
            }
            next = curr;
        }
        return curr[0][0];
    }
};