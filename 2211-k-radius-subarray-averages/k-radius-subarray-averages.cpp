class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        long long subArrSum = 0;
        vector<int> ans(n,-1);
        if(2*k+1 > n)
            return ans;
        for(int i=0; i<2*k+1; i++)
            subArrSum += nums[i];
        ans[k] = subArrSum / (2*k+1);
        for(int i=k+1; i<n-k; i++){
            subArrSum -= nums[i-k-1];
            subArrSum += nums[i+k];
            ans[i] = subArrSum / (2*k+1);
        }
        return ans;
        //Brute : TLE : TC=O(k+1)n
        // int n = nums.size();
        // vector<int> ans;
        // for(int i=0; i<n; i++){
        //     if(0 <= i-k && i+k < n){
        //         int sum = 0, avg;
        //         for(int j=i-k; j<=i+k; j++){
        //             sum += nums[j];
        //         }
        //         avg = sum/(2*k+1);
        //         ans.push_back(avg);
        //     }
        //     else    ans.push_back(-1);
        // }
        // return ans;
    }
};