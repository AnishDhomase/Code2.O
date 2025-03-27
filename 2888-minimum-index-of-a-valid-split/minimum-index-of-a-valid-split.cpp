class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;
        int dominantNum, dominantNumFreq = 0;
        for(auto num: nums) freq[num] ++;
        for(auto it: freq){
            int num = it.first;
            int frequencyOfNum = it.second;
            if(frequencyOfNum > n/2){
                dominantNum = num;
                dominantNumFreq = frequencyOfNum;
                break;
            }
        }
        int cntOfDomInLeftSplittedArray = 0;
        for(int i=0; i<n-1; i++){
            if(nums[i] == dominantNum)  cntOfDomInLeftSplittedArray ++;
            int leftSplittedArrayLen = i+1;
            int rightSplittedArrayLen = n-(i+1);
            int cntOfDomInRightSplittedArray 
                    = dominantNumFreq - cntOfDomInLeftSplittedArray;
            if(cntOfDomInLeftSplittedArray > leftSplittedArrayLen/2 &&
                cntOfDomInRightSplittedArray > rightSplittedArrayLen / 2)
                return i;   
        }
        return -1;
    }
};