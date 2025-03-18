class Solution {
    void markBitPositions(int num, vector<int>& bitArray){
        for(int i=0; i<32; i++)
            if((num & (1<<i)) > 0)
                bitArray[i] ++;
    }
    void unMarkBitPositions(int num, vector<int>& bitArray){
        for(int i=0; i<32; i++)
            if((num & (1<<i)) > 0)
                bitArray[i] --;
    }
    bool isAllUniqueBitPositions(vector<int>& bitArray){
        for(auto bit: bitArray)
            if(bit > 1) return false;
        return true;
    }
public:
    int longestNiceSubarray(vector<int>& nums) {
        vector<int> bitArray(32, 0);
        int i=0, j=0, n=nums.size(), longestNiceSubarrLen = 1;
        while(j<n){
            markBitPositions(nums[j], bitArray);
            while(!isAllUniqueBitPositions(bitArray)){
                unMarkBitPositions(nums[i], bitArray);
                i ++;
            }
            longestNiceSubarrLen = max(longestNiceSubarrLen, j-i+1);
            j ++;
        }
        return longestNiceSubarrLen;
    }
};