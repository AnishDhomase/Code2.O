class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ansU(nums2.size());
        vector<int> ans;
        stack<int> st;
        for(int i=nums2.size()-1; i>=0; i--){
            while(st.size() && st.top()<nums2[i]){
                st.pop();
            }
            if(st.size()==0)
                ansU[i]=-1;
            else ansU[i]=st.top();
            st.push(nums2[i]);
        }
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i]==nums2[j]){
                    ans.push_back(ansU[j]);
                    break;
                }
            }
        }
        return ans;
    }
};