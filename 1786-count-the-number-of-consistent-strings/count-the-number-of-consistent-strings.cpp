class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt = 0;
        unordered_map<char,int> mp;
        for(auto ch: allowed) mp[ch] ++;
        for(auto word: words) {
            bool isConsistent  = true;
            for(auto ch: word) {
                if(mp[ch] == 0) {
                    isConsistent = false;
                    break;
                }
            }
            if(isConsistent) cnt ++;
        }
        return cnt;
    }
};