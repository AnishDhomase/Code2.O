class Solution {
    bool isValidSubstring(vector<int> &word1Mp, vector<int> &word2Mp){
        for(int i=0; i<26; i++){
            if(word1Mp[i] < word2Mp[i])
                return false;
        }
        return true;
    }
public:
    long long validSubstringCount(string word1, string word2) {
        long long cnt = 0;
        vector<int> word1Mp(26,0), word2Mp(26,0);
        for(auto ch : word2)
            word2Mp[ch-'a'] ++;
        int l=0, r=0, n=word1.length();
        while(r<n){
            word1Mp[word1[r]-'a'] ++;
            if(isValidSubstring(word1Mp, word2Mp)){
                cnt += (n-r);
                word1Mp[word1[l]-'a'] --;
                l ++;
                word1Mp[word1[r]-'a'] --;            
            }
            else{
                r ++;
            }
        }
        return cnt;

    }
};