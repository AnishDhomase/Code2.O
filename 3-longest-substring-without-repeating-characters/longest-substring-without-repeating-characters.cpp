class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, n = s.length(), maxL=0;
        set<char> st;
        while(l<=r && r<n){
            if(st.find(s[r]) == st.end()){
                st.insert(s[r]);
                r ++;
                maxL = max(maxL, r-l);
                continue;
            }
            else while(s[l] != s[r]){
                st.erase(s[l]);
                l ++;
            }
            l ++;
            r ++;
        }
        maxL = max(maxL, r-l);
        return maxL;
    }
};