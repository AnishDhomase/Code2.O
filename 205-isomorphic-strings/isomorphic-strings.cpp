class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.length();
        unordered_map<char,char> mpp;
        for(int i=0; i<len; i++)
        {
            if(mpp[s[i]]){
                if(mpp[s[i]] != t[i])   return false;
            }
            else{
                for(auto elem : mpp){
                    if(t[i] == elem.second)
                        return false;
                }
                mpp[s[i]] = t[i];
            }
        }
        return true;
    }
};