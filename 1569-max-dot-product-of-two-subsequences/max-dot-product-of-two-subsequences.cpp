class Solution {
    int getMaxProd(int i, int j, int nonEmptySeq, vector<int>& nums1, vector<int>& nums2, vector<vector<vector<int>>> &dp){
        if(i == 0 || j == 0){
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
        // return getMaxProd(sz1, sz2, 0, nums1, nums2, dp);
        vector<vector<vector<int>>> dp(sz1+1, vector<vector<int>>(sz2+1, vector<int>(2, 0)));
        for(int i=0; i<=sz1; i++)   dp[i][0][0] = INT_MIN;
        for(int j=0; j<=sz2; j++)   dp[0][j][0] = INT_MIN;
        
        for(int i=1; i<=sz1; i++){
            for(int j=1; j<=sz2; j++){
                for(int nonEmptySeq=1; nonEmptySeq>=0; nonEmptySeq--){
                    int way1 = nums1[i-1] * nums2[j-1] + dp[i-1][j-1][1];
                    int way2 = dp[i-1][j][nonEmptySeq];
                    int way3 = dp[i][j-1][nonEmptySeq];

                    dp[i][j][nonEmptySeq] = max(way1, max(way2, way3));
                }
            }
        }
        return dp[sz1][sz2][0];
    }
};