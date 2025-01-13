class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        for(auto ch: s)
            freq[ch-'a'] ++;
        int len = 0;
        for(auto f: freq){
            if(f >= 3){
                if(f % 2 == 0)  len += 2;
                else            len += 1;
            }
            else    len += f; 
        }
        return len;
    }
};