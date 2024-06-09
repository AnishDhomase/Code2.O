class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0, count = 0;
        unordered_map<int,int> freq;
        freq[0]++;
        for(auto num : nums){
            sum += num;
            if(sum < 0){
                int absSum = abs(sum);
                if(absSum % k == 0) freq[0]++;
                else freq[k - (absSum % k)]++;
            } 
            else        freq[sum % k]++;
        }
        for(auto it: freq){
            int f = it.second - 1;
            count += f*(f+1)/2;
        }
        return count;


        // O(n^2)
        // int n = nums.size(), count = 0;
        // for(int i=0; i<n; i++){
        //     int sum = 0;
        //     for(int j=i; j<n; j++){
        //         sum += nums[j];
        //         if(sum % k == 0)    count++;
        //     }
        // }
        // return count;
    }
};