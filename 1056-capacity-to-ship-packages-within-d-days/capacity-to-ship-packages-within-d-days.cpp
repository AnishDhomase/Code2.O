class Solution {
    bool isCapEnough(int cap, vector<int> weights, int days){
        int d = 0, sum=0;
        for(int i=0; i<weights.size(); i++){
            if(weights[i] > cap)    return false;
            sum += weights[i];
            if(sum > cap){
                i--;
                d++;
                sum=0;
            }
        }
        return d+1 <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        for(auto w : weights)
            sum+=w;
        int low = 1, high = sum, ans;
        while(low <= high){
            int mid = low + (high-low)/2;
            bool enough = isCapEnough(mid, weights, days);
            if(enough){
                ans = mid;
                high = mid-1;
            }
            else    low = mid+1;
        }
        return ans;
    }
};