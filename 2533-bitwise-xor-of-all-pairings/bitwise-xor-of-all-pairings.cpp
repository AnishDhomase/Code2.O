class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xr = 0, n1 = nums1.size(), n2 = nums2.size();
        if(n2 % 2 == 1)
            for(auto num: nums1)    xr ^= num;
        if(n1 % 2 == 1)
            for(auto num: nums2)    xr ^= num;
        return xr;
    }
};