class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k == 1)  return nums;

        int n = nums.size();
        vector<int> ans;
        int streak = 1, prev = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] == prev + 1){
                prev = nums[i];
                streak ++;
                if(streak >= k)
                    ans.push_back(nums[i]);
                else if(k <= i+1)
                    ans.push_back(-1);
            }
            else{
                prev = nums[i];
                streak = 1;  
                if(k <= i+1)
                    ans.push_back(-1);
            }
        }
        return ans;

    }
};