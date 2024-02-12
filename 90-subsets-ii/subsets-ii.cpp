class Solution {
    void fun(int ind, vector<int> subset, vector<vector<int>> &ans, vector<int> nums, int n){
        ans.push_back(subset);
        if(ind > n) return;
        int prevUnique;
        for(int i=ind; i<=n; i++){
            if(i==ind || nums[i]!=prevUnique){
                prevUnique = nums[i];
                subset.push_back(nums[i]);
                fun(i+1,subset,ans,nums,n);
                subset.pop_back();
            }
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        sort(nums.begin(),nums.end());
        fun(0,sub,ans,nums,nums.size()-1);
        return ans;
        
    }
};