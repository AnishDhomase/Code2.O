class Solution {
    bool isThisDayWillGiveMbqts(int day, vector<int> bloomDay, int m, int k){
        int streak = 0, numOfBqts = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= day)
                streak++;
            else   streak=0; 
            if(streak==k){
                streak = 0;
                numOfBqts++;
            } 
        }
        return (numOfBqts >= m);
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(), maxBloomDay, ans;
        if((long long)n < (long long)m*k) return -1;
        for(auto day : bloomDay){
            maxBloomDay = max(maxBloomDay, day);
        }
        int dLow = 1, dHigh = maxBloomDay;
        while(dLow <= dHigh){
            int dMid = dLow + (dHigh-dLow)/2;
            bool enough = isThisDayWillGiveMbqts(dMid, bloomDay, m, k);
            if(enough){
                ans = dMid;
                dHigh = dMid-1;
            }
            else
                dLow = dMid + 1;
        }
        return ans;

    }
};