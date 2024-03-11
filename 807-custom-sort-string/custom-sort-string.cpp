class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        string ans;
        for(auto ch : s)
            mp[ch]++;
        for(auto ch : order){
            string str(mp[ch], ch);
            ans += str;
            mp[ch] = 0;
        }
        for(auto it : mp){
            string str(it.second, it.first);
            ans += str;
        }
        return ans;
    }
};