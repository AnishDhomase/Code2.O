typedef long long LL;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        LL cntOfValidSubarrays = 0;
        int maxElem = *max_element(nums.begin(), nums.end());
        int cntOfMaxElem = 0, n = nums.size(), i, j;
        cntOfMaxElem = i = j = 0;
        while(j<n){
            if(nums[j] == maxElem)  cntOfMaxElem ++;
            while(cntOfMaxElem == k){
                cntOfValidSubarrays += (LL) n - j;
                if(nums[i] == maxElem)  cntOfMaxElem --;
                i ++;
            }
            j ++;
        }
        return cntOfValidSubarrays;
    }

};