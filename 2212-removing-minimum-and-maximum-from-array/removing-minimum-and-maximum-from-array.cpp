class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxElemInd = max_element(nums.begin(), nums.end()) - nums.begin();
        int minElemInd = min_element(nums.begin(), nums.end()) - nums.begin();

        int minDel;
        if(maxElemInd == minElemInd)
            minDel =  min(maxElemInd+1, n-maxElemInd);
        else{
            int low = min(maxElemInd, minElemInd);
            int high = max(maxElemInd, minElemInd);
            minDel = min(high+1, min(n-low, low+1+n-high));
        }
        return minDel;
        
    }
};