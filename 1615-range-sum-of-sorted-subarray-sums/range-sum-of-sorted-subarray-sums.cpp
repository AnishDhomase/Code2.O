class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod = 1e9 + 7, rangeSumArr=0;
        vector<int> sums;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                sums.push_back(sum);
            }
        }
        partial_sort(sums.begin(), sums.begin() + right,
                   sums.end());
        for(int i=left-1; i <= right-1; i++){
            rangeSumArr = (rangeSumArr + sums[i]) % mod;
        }
        return rangeSumArr % mod;
        
    }
};