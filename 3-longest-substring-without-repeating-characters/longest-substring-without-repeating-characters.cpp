class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, n = s.length(), maxL=0;
        unordered_map<char,int> mp;
        while(r<n){
            if(mp.find(s[r]) != mp.end()){
                if(mp[s[r]] >= l)
                    l = mp[s[r]] + 1; 
            }
            maxL = max(maxL, r-l+1);
            mp[s[r]] = r;
            r ++;
        }
        return maxL;
    }
};