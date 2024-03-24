class Solution {
    bool isThisDivisorIsAnswer(int divisor, vector<int> nums, int threshold){
        long long sum = 0;
        for(auto num : nums){
            sum += num/divisor;
            if(num%divisor) sum+=1;
        }
        return sum <= threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = 1e9, ans;
        while(low <= high){
            int mid = low + (high-low)/2;
            bool enough = isThisDivisorIsAnswer(mid, nums, threshold);
            if(enough){
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;  
        }
        return ans;
    }
};