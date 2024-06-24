class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        unordered_map<int,int> mp;
        int n = arr.size();
        mp[-1] = 0;
        for(int i=0, xr=0; i<n; i++){
            xr ^= arr[i];
            mp[i] = xr;
        }
        for(auto q : queries){
            int start=q[0], end=q[1];
            ans.push_back(mp[start-1] ^ mp[end]);
        }
        return ans;
    }
};