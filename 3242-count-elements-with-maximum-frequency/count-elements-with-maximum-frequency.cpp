class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>  freq;
        for(auto e : nums)
            freq[e]++;
        int elemWithMaxFreq = 0, maxFreq = 0;
        for(auto it : freq){
            if(maxFreq < it.second){
                elemWithMaxFreq = 1;
                maxFreq = it.second;
            }
            else if(maxFreq == it.second)
                elemWithMaxFreq ++;
        }
        return elemWithMaxFreq * maxFreq;
    }
};