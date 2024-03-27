class Solution {
    long long getPossibleChlids(int candy, vector<int> candies){
        if(candy==0)    return 1e9;
        long long childs = 0;
        for(auto pile : candies){
            childs += (long long) pile/candy;
        }
        return childs;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int ans=0;
        int low = 0, high = *max_element(candies.begin(), candies.end());
        while(low <= high){
            int mid = low + (high-low)/2;
            long long childs = getPossibleChlids(mid, candies);
            if(childs >= k){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};