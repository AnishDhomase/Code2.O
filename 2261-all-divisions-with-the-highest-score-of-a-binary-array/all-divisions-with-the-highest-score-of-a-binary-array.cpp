class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int> ans;
        int maxScore = 0, n=nums.size();
        int leftArrZeroes = 0, rightArrOnes = 0;
        for(auto num : nums)    
            if(num == 1)    
                rightArrOnes++;
        for(int divisionAtIndex = 0; divisionAtIndex <= n; divisionAtIndex ++){
            int score = leftArrZeroes + rightArrOnes;
            if(score > maxScore){
                maxScore = score;
                ans.clear();
                ans.push_back(divisionAtIndex);
            }
            else if(score == maxScore){
                ans.push_back(divisionAtIndex);
            }
            if(divisionAtIndex == n)    break;
            leftArrZeroes += nums[divisionAtIndex] == 0 ? 1 : 0;
            rightArrOnes  += nums[divisionAtIndex] == 1 ? -1 : 0;
        }
        return ans;

    }
};