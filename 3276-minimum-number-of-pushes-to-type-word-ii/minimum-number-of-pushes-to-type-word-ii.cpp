class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        unordered_map<char,int> freq;
        priority_queue<int> maxHeap;
        for(auto ch: word)
            freq[ch] ++;
        for(auto it: freq){
            int freqOfChar = it.second;
            maxHeap.push(freqOfChar);
        }
        int i=0;
        while(maxHeap.size()) {
            int freqOfChar = maxHeap.top();
            maxHeap.pop();
            i++;
            int numKeyPushReqToTypeThisChar = (i-1)/8 + 1;
            ans += numKeyPushReqToTypeThisChar * freqOfChar;
        }
        return ans;  
    }
};