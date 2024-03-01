class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        unordered_map<char,int> mp;
        int n = s.length();
        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }
        string ans="1";
        mp['1']--;
        for( ; mp['0']; ){
            ans = '0' + ans;
            mp['0']--;
        }
        for( ; mp['1']; ){
            ans = '1' + ans;
            mp['1']--;
        }
        return ans;
    }
};