class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string ans;
        vector<int> freq(26, 0);
        for(auto ch: s) freq[ch-'a']++;
        int i=24, j=25;
        while(i>=0 && j>=0){
            if(freq[j] == 0){
                j--;
                if(j >= 0 && freq[j] != 0)  i = j-1;
                continue;
            }   
            if(freq[i] == 0){
                i--;
                continue;
            }
            int len = min(freq[j], repeatLimit);
            char ch = j + 'a', delemiter = i + 'a';
            if(ans.length() > 0 && ans.back() == ch && freq[j] >= repeatLimit) len --;
            freq[j] -= len;
            freq[i] --;

            string last(len, ch);
            ans += last;
            ans += delemiter;
        }
        if(i < 0){
            int len = min(freq[j], repeatLimit);
            char ch = j + 'a';
            if(ans.length() > 0 && ans.back() == ch && freq[j] >= repeatLimit) len --;

            string last(len, ch);
            ans += last;
        }
        return ans;

    }
};