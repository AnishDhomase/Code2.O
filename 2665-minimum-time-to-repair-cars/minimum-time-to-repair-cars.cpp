class Solution {
    bool isPossibleToRepairUnderTime(long long time, vector<int> &ranks, int cars){
        int c = 0;
        for(auto r : ranks){
            c += pow(time/r, 0.5);
            if(c >= cars)
                return true;
        }
        return false;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1, high = (long long)*min_element(ranks.begin(), ranks.end()) * cars * cars;
        long long minTime;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(isPossibleToRepairUnderTime(mid, ranks, cars)){
                minTime = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            } 
        } 
        return minTime;
    }
};