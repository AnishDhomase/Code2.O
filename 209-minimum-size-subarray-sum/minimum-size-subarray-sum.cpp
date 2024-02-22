class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = 1e9;
        long long sum = 0;
        int n = nums.size();
        int i=0, j=0;
        while(i<=j && j<n){
            sum += nums[j];
            if(target <= sum){
                while(target <= sum){
                    minLen = (j-i+1 < minLen) ? (j-i+1) : minLen;
                    sum -= nums[i];
                    i++;
                }
                j++;
            }
            else{
                j++;
            }
        }
        if(minLen == 1e9)   return 0;
        return minLen;
        

        //Brute : Generate all subsets and check
        //TC = O(2^n)
    }
};