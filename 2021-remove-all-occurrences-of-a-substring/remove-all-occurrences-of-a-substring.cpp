class Solution {
public:
    string removeOccurrences(string s, string part) {
        int m = part.length();
        string ans;
        for(auto ch: s){
            ans += ch;
            int n = ans.length();
            if(n-m >= 0){
                string lastSubstr = ans.substr(n-m, m);
                if(lastSubstr == part)
                    ans = ans.substr(0, n-m);
            }
        }
        return ans;
    }
};