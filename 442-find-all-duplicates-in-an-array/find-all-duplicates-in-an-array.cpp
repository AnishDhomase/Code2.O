class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(auto elem : nums){
            int e = abs(elem);
            if(nums[e-1] < 0){
                ans.push_back(e);
            }
            else{
                nums[e-1] *= -1;
            }
        }
        return ans;
    }
};