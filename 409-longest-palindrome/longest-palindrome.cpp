class Solution {
public:
    int longestPalindrome(string s) {
        int maxLen = 0;
        unordered_map<char,int> mp;
        for(auto ch : s)    mp[ch]++;
        int single = false;
        for(auto it : mp){
            int freq = it.second;
            maxLen += (freq / 2) * 2;
            if(freq % 2 == 1) single = true;
        }
        return single ? maxLen+1 : maxLen;
    }
};