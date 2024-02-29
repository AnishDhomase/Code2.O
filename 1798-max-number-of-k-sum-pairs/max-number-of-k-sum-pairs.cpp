class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> freq; //{elem, freqofElem}
        for(auto e : nums)
            freq[e]++;
        for(auto e : nums){
            if(freq[e]){
                freq[e]--;
                int possiblePairMate = k - e;
                if(freq[possiblePairMate]){
                    freq[possiblePairMate]--;
                    ans++;
                }
                
            }
        }
        return ans;
    }
};