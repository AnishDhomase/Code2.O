class Solution {
    int getSeq(vector<int> &freq){
        int seq = 1;
        for(int i=0; i<26; i++){
            if(freq[i]>0){
                freq[i]--;
                seq += getSeq(freq);
                freq[i] ++;
            }                      
        }
        return seq;
    }
public:
    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);
        for(auto t: tiles)  freq[t-'A']++;
        return getSeq(freq) - 1;
    }
};