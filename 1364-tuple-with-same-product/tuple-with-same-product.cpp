class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int,set<pair<int,int>>> mp;
        int n = nums.size(), cnt = 0;;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] != nums[j]){
                    int sm = min(nums[i], nums[j]);
                    int lg = max(nums[i], nums[j]);
                    mp[sm*lg].insert({sm, lg});
                }
            }
        }
        for(auto it: mp){
            int totalPairs = it.second.size();
            cnt += 8 * (totalPairs * (totalPairs-1) / 2);
        }
        return cnt;

    }
};