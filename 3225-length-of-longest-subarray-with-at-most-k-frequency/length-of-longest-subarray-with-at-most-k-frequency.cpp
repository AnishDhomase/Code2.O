class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxLen=0, n=nums.size();
        unordered_map<int,int> freq;
        int i=0, j=0;
        while(i<n){
            while(j<n && freq[nums[j]] + 1 <= k){
                freq[nums[j]]++;
                j++;
            }
            maxLen = max(maxLen, j-i);
            if(j==n)
                break;
            freq[nums[i]]--;
            i++;
        }
        return maxLen;
    }
};