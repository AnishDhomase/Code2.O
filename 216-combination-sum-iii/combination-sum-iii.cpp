class Solution {
    void getCombis(vector<int> &taken, int start, int sum, int k, vector<vector<int>> &ans){
        if(taken.size() == k){
            if(sum == 0)    ans.push_back(taken);
            return;
        }
        if(sum == 0)   return;

        for(int i=start; i<=9; i++){
            if(sum - i < 0) break;
            taken.push_back(i);
            getCombis(taken, i+1, sum-i, k, ans);
            taken.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> taken;
        getCombis(taken, 1, n, k, ans);
        return ans;
    }
};