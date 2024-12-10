class Solution {
public:
    int maximumLength(string s) {
        map<char, priority_queue<int>> mp;
        int freq = 1, n = s.length(), ans = -1;
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1])  freq ++;
            else{
                mp[s[i-1]].push(freq);
                freq = 1;
            }
        }
        mp[s[n-1]].push(freq);
        for(auto it: mp){
            auto mxHeap = it.second;
            auto maxHeapSize = mxHeap.size();
            int topFreq = mxHeap.top();
            if(topFreq >= 3)    ans = max(ans, topFreq-2);

            if(maxHeapSize >= 2){
                auto maxHeap = it.second;
                int topFreq = maxHeap.top();
                if(topFreq >= 2){
                    maxHeap.pop();
                    int secTopFreq = maxHeap.top();
                    if(topFreq > secTopFreq)    ans = max(ans, secTopFreq);
                    else                        ans = max(ans, secTopFreq-1);
                }
            }
            if(maxHeapSize >= 3){
                auto maxHeap = it.second;
                maxHeap.pop();
                maxHeap.pop();
                int thirdTopFreq = maxHeap.top();
                ans = max(ans, thirdTopFreq);
            }
        }
        return ans;     
    }
};