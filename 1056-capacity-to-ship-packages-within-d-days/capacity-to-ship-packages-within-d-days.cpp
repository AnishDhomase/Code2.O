class Solution {
    bool isCapEnough(int cap, vector<int> &weights, int days){
        int d = 1, sum=0;
        for(auto w: weights){
            if(sum + w <= cap)
                sum += w;
            else{
                d ++;
                sum = w;
            }

        }
        return d <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        for(auto w : weights)
            sum+=w;
        int low = *max_element(weights.begin(), weights.end()), high = sum, ans;
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