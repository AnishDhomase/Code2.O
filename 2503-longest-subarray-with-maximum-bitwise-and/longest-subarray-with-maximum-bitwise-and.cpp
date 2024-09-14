class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int streak = 1, maxStreak = 1, prevNum = nums[0], maxNum = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == prevNum) streak ++;
            else {   
                if(nums[i] > maxNum) {
                    maxNum = nums[i];
                    maxStreak = 1;
                }
                else if(prevNum == maxNum) maxStreak = max(maxStreak, streak);
                streak = 1;
                prevNum = nums[i];
            }
        }
        if(prevNum == maxNum) maxStreak = max(maxStreak, streak);
        return maxStreak;
    }
};