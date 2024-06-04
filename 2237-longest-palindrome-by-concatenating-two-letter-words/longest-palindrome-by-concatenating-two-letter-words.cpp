class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> freqMp;
        int same = false, maxLen = 0;

        for(auto w : words) freqMp[w]++;
        for(auto it : freqMp){
            string word = it.first;
            int wordFreq = it.second;
            if(word[0] == word[1]){
                maxLen += (wordFreq%2 == 0) ? (wordFreq*2) : (wordFreq-1)*2;
                if(wordFreq%2 == 1) same = true;
            }
            else{
                string wordCopy = word;
                reverse(wordCopy.begin(), wordCopy.end());
                string oppoWord = wordCopy; 
                int oppoWordFreq = freqMp[oppoWord];
                int pairsContributingToFinalPalindrome = min(wordFreq, oppoWordFreq);
                maxLen += pairsContributingToFinalPalindrome * 2 * 2;
                freqMp[oppoWord] = 0;
            }
        }
        return same ? maxLen + 2 : maxLen;
    }
};