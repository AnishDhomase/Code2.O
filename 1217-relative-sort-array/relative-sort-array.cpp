class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        map<int,int> mp;
        for(auto e : arr1)
            mp[e]++;
        for(auto e : arr2){
            ans.insert(ans.end(), mp[e], e);
            mp.erase(e);
        }
        for(auto it : mp)
            ans.insert(ans.end(), it.second, it.first);
        
        return ans;
    }
};