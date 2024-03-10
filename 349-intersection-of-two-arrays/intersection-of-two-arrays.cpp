class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        vector<int> ans;
        for(auto e : nums1)
            st.insert(e);
        for(auto e : nums2)
            if(st.find(e) != st.end()){
                st.erase(e);
                ans.push_back(e);
            }

        return ans;
                
    }
};