class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int K = k, initialTotalUniqueNums;
        unordered_map<int,int> mp;  //{number,frequency}
        map<int,int> freq;  //{frequency,no. of numbers}
        for(auto e : arr)
            mp[e]++;
        for(auto it : mp)
            freq[it.second]++;
        initialTotalUniqueNums = mp.size();
        for(auto it : freq){
            int fq = it.first;
            int ctOfNums = it.second;
            while(K>=fq && ctOfNums){
                K-=fq;
                ctOfNums--;
                initialTotalUniqueNums--;
            }
            if(ctOfNums)    break;
        }
        return initialTotalUniqueNums;
    }
};