class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size(), i=0, j, k, prevI, prevJ, prevK;
        sort(nums.begin(), nums.end());
        while(i<=n-3){
            prevI = nums[i];
            j=i+1;
            k=n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    prevJ = nums[j];
                    prevK = nums[k];
                    while(j<n && nums[j] == prevJ)
                        j++;
                    while(k>i && nums[k] == prevK)
                        k--;
                }
                else if(sum < 0)    j++;
                else                k--;
            }
            while(i<=n-2 && nums[i] == prevI)
                i++;
        }
        return ans;

        // int n = nums.size();
        // unordered_map<int,vector<int>> mp;
        // set<vector<int>> st;
        // for(int i=0; i<n; i++)
        //     mp[nums[i]].push_back(i);
        // for(int i=0; i<=n-2; i++){
        //     for(int j=i+1; j<=n-1; j++){
        //         auto indArr = mp[-(nums[i]+nums[j])];
        //         for(auto ind : indArr){
        //             if(ind != i && ind != j){
        //                 vector<int> triplet = {nums[i], nums[j], nums[ind]};
        //                 sort(triplet.begin(), triplet.end());
        //                 st.insert(triplet);
        //                 break;
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>> ans(st.begin(), st.end());
        // return ans;

        
    }
};