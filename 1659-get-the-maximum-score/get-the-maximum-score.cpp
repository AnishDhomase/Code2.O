typedef long long LL;
class Solution {
    int mod = 1e9 + 7;
    int canSwitch(int i, int arr1, vector<int>& nums1, vector<int>& nums2){
        int val = arr1 == 1 ? nums1[i] : nums2[i];
        int m = arr1 == 1 ? nums2.size() : nums1.size();

        if(arr1){
            int lb = lower_bound(nums2.begin(), nums2.end(), val) - nums2.begin();
            if(lb == m || nums2[lb] != val) return -1;
            int ub = upper_bound(nums2.begin(), nums2.end(), val) - nums2.begin();
            return ub;
        }
        int lb = lower_bound(nums1.begin(), nums1.end(), val) - nums1.begin();
        if(lb == m || nums1[lb] != val) return -1;
        int ub = upper_bound(nums1.begin(), nums1.end(), val) - nums1.begin();
        return ub;
    }
    LL getMaxSum(int i, int arr1, vector<int>& nums1, vector<int>& nums2, vector<vector<LL>> &dp){
        int n = arr1 == 1 ? nums1.size() : nums2.size();
        if(i == n)  return 0;
        if(dp[i][arr1] != -1)   return dp[i][arr1];

        LL val = arr1 == 1 ? nums1[i] : nums2[i];
        // stay
        LL stay = val + getMaxSum(i+1, arr1, nums1, nums2, dp);
        // switch
        LL noStay = 0;
        int ub = canSwitch(i, arr1, nums1, nums2);
        if(ub != -1)
            noStay = val + getMaxSum(ub, !arr1, nums1, nums2, dp);
        
        return dp[i][arr1] = max(stay, noStay);
    }
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), maxNM = max(n,m);
        vector<vector<LL>> dp(maxNM, vector<LL>(2, -1));
        LL startFrom1 = getMaxSum(0, 1, nums1, nums2, dp);
        LL startFrom2 = getMaxSum(0, 0, nums1, nums2, dp);
        return max(startFrom1, startFrom2) % mod;
    }
};