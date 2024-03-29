class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ct = 0;
        vector<int> maxPos;
        int n = nums.size(), maxElem = *max_element(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            if(nums[i]==maxElem)
                maxPos.push_back(i);
        }
        for(int i=0, j=k-1; j<maxPos.size(); i++,j++){
            int l = maxPos[i]+1, r = n-maxPos[j];
            if(i!=0) l = maxPos[i] - maxPos[i-1];
            ct += (long long) l * r;
        }
        return ct;
    }
};