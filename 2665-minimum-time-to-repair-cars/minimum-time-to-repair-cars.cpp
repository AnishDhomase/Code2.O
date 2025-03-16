typedef long long LL;
class Solution {
    bool isPossibleToRepair(LL maxTimePerMechanic, vector<int>& ranks, int cars){
        for(auto rank: ranks){
            // rn^2 <= maxTimePerMechanic
            // n <= sqrt(maxTimePerMechanic / r)
            int maxNForWorker = sqrt(maxTimePerMechanic / rank);

            cars -= maxNForWorker;
            if(cars <= 0)  return true;
        }
        return false;   
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        LL low = 0, ans;
        LL high = pow(cars,2) * *max_element(ranks.begin(), ranks.end());
        while(low <= high){
            LL mid = (low + high) / 2;
            if(isPossibleToRepair(mid, ranks, cars)){
                ans = mid;
                high = mid - 1;
            }
            else    low = mid + 1;
        }
        return ans;
    }
};