class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n = text.length();
        unordered_set<string> st;
        for(int i=0; i<n; i++){
            string str;
            for(int j=i+1; j<n; j+=2){
                int l = j-i+1;
                string leftHalf = text.substr(i, l/2);
                string rightHalf = text.substr(i+l/2, l/2);
                if(leftHalf == rightHalf)
                    st.insert(leftHalf);
            }
        }
        return st.size();
    }
};