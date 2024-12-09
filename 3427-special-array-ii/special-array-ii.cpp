class Solution {
    int justSmallerOrEqual(int x, vector<int> &arr){
        int n = arr.size();
        int l=0, h=n-1, ans;
        while(l <= h){
            int m = l + (h-l)/2;
            if(x < arr[m])  h = m-1;
            else{
                ans = m;
                l = m+1;
            }
        }
        return ans;
    }
    bool oppoParity(int n1, int n2){
        return (n1 % 2) != (n2 % 2);
    }
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> leader={0};
        vector<bool> ans;
        for(int i=1; i<n; i++){
            if(!oppoParity(nums[i-1], nums[i]))
                leader.push_back(i);   
        }
        for(int i=0; i<m; i++){
            int left = queries[i][0], right = queries[i][1];
            int leader1 = justSmallerOrEqual(left, leader);
            int leader2 = justSmallerOrEqual(right, leader);
            ans.push_back(leader1 == leader2);
        }
        return ans;
    }
};