class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0, fliped=0;
        int n=nums.size(), i=0, j=0;
        while(j<n){
            if(nums[j]==1)  j++;
            else{
                if(!k){
                    maxLen = max(maxLen, j-i);
                    i=j+1;
                    j=i;
                }
                else if(fliped<k){
                    fliped++;
                    nums[j]=2;
                    j++;
                }
                else{
                    maxLen = max(maxLen, j-i);
                    while(nums[i] != 2)
                        i++;
                    fliped--;
                    nums[i]=0;
                    i++;
                }
            }
        }
        maxLen = max(maxLen, j-i);
        return maxLen;
    }
};