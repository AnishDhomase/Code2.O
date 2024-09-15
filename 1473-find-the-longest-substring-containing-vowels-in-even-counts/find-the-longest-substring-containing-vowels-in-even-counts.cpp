class Solution {
    bool isVovel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }
public:
    int findTheLongestSubstring(string s) {
        int longest = 0, xr = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for(int i=0; i<s.length(); i++){
            if(isVovel(s[i]))
                xr ^= s[i];
            if(mp.find(xr) != mp.end())
                longest = max(longest, i - mp[xr]);
            else
                mp[xr] = i;   
        }
        return longest;
    }
};