class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        map<vector<int>, int> mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            vector<int> v;
            int divs = 0;
            for(int j=i; j<n; j++){
                v.push_back(nums[j]);
                if(nums[j] % p == 0)
                    divs++;
                if(divs <= k)
                    mp[v]++;
                else break;
            }
        }
        return mp.size();
    }
};