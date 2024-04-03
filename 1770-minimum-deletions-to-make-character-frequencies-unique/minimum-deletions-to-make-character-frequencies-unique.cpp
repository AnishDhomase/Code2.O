class Solution {
public:
    int minDeletions(string s) {
        int del = 0;
        unordered_set<int> st;
        unordered_map<char,int> freq;
        for(auto ch : s)    freq[ch]++;
        for(auto it : freq){
            int f = it.second;
            if(st.find(f) == st.end()){
                st.insert(f);
            }
            else while(f && st.find(f) != st.end()){
                f--;
                del++;
            }
            if(f)   st.insert(f);
        }
        return del;

    }
};