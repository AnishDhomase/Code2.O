class Solution {
    int getMaxProd(int i, int j, int nonEmptySeq, vector<int>& nums1, vector<int>& nums2, vector<vector<vector<int>>> &dp){
        if(i-1 == -1 || j-1 == -1){
            if(nonEmptySeq) return 0;
            return INT_MIN;
        }   
        if(dp[i][j][nonEmptySeq] != 1e9)   return dp[i][j][nonEmptySeq];

        int way1 = nums1[i-1] * nums2[j-1] + getMaxProd(i-1, j-1, 1, nums1, nums2, dp);
        int way2 = getMaxProd(i-1, j, nonEmptySeq, nums1, nums2, dp);
        int way3 = getMaxProd(i, j-1, nonEmptySeq, nums1, nums2, dp);

        return dp[i][j][nonEmptySeq] = max(way1, max(way2, way3));
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size(), sz2 = nums2.size();
        // vector<vector<vector<int>>> dp(sz1, vector<vector<int>>(sz2, vector<int>(2, 1e9)));
        vector<vector<vector<int>>> dp(sz1+1, vector<vector<int>>(sz2+1, vector<int>(2, 1e9)));
        return getMaxProd(sz1, sz2, 0, nums1, nums2, dp);

    }
};