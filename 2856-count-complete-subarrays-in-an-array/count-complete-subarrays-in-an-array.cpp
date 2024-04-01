class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int> freq, freqk, freqk_1;
        for(auto e : nums)
            freq[e]++;
        int k = freq.size();
        int ctk=0, ctk_1=0;
        int i=0, j=0, n=nums.size();
        while(i<=j && j<n){
            freqk[nums[j]]++;
            if(freqk.size() <= k){
                ctk += j-i+1;
                j++;
            }
            else{
                while(freqk.size() > k){
                    freqk[nums[i]]--;
                    if(freqk[nums[i]] == 0)
                        freqk.erase(nums[i]);
                    i++;
                }
                freqk[nums[j]]--;
            }
        }
        i=0; j=0;
        if(k-1)
        while(i<=j && j<n){
            freqk_1[nums[j]]++;
            if(freqk_1.size() <= k-1){
                ctk_1 += j-i+1;
                j++;
            }
            else{
                while(freqk_1.size() > k-1){
                    freqk_1[nums[i]]--;
                    if(freqk_1[nums[i]] == 0)
                        freqk_1.erase(nums[i]);
                    i++;
                }
                freqk_1[nums[j]]--;
            }
        }
        return ctk - ctk_1;
    }
};