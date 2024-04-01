class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size(), i=0, j=0, sum=0, maxScore=0;
        unordered_map<int,int> freq;
        while(i<=j && j<n){
            freq[nums[j]]++;
            sum += nums[j];
            if(freq[nums[j]] == 1)
                j++;
            else{
                maxScore = max(maxScore, sum-nums[j]);
                while(freq[nums[j]] > 1){
                    freq[nums[i]]--;
                    sum -= nums[i];
                    i++;
                }
                j++;
            }
        }
        maxScore = max(maxScore, sum);
        return maxScore;
    }
};