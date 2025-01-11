class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> freq(26, 0);
        for(auto ch: s)
            freq[ch-'a'] ++;
        int cnt = 0, evens = 0;
        for(int i=0; i<26; i++){
            if(freq[i] % 2 == 1){
                cnt ++;
                freq[i] --;
            }
            evens += freq[i];
        }
        if(cnt > k) return false;
        if(cnt == k) return true;
        while(k-cnt >= 2){
            if(evens >= 2){
                evens -= 2;
                cnt += 2;
            }
            else    return false;
        }
        if(k-cnt == 0)  return true;
        return evens > 0;    
    }
};