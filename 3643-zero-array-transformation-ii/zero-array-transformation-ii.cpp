class Solution {
    bool isAllZeroPossible(int k, vector<int> diff, vector<vector<int>>& queries) {
        int n = diff.size();
        
        for(int i=0; i<k; i++){
            int l = queries[i][0], r = queries[i][1], val = queries[i][2];
            diff[l] -= val;
            if(r+1 < n) diff[r+1] += val;
        }
        int sum = 0;
        for(auto val: diff){
            sum += val;
            if(sum > 0) return false;
        }
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> diff = {nums[0]};
        for(int i=1; i<n; i++)  diff.push_back(nums[i]-nums[i-1]);

        int low = 0, high = queries.size(), ans = -1; 
        while(low <= high){
            int mid = (low + high)/2;
            if(isAllZeroPossible(mid, diff, queries)){
                ans = mid;
                high = mid - 1;
            }
            else    low = mid + 1;
        }
        return ans;
    }
};