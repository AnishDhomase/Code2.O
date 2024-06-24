class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Optimal: TC=O()
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n=nums.size(), i=0, j, k, l;
        while(i <= n-4){
            j=i+1;  
            while(j <= n-3){
                k=j+1;
                l=n-1;
                while(k<l){
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while(k<n && nums[k] == nums[k-1]) k++;
                        while(l>j && nums[l] == nums[l+1]) l--;
                    }
                    else if(sum < target)   k++;
                    else l--;
                }
                j++;
                while(j<n && nums[j] == nums[j-1])
                    j++;
            }
            i++;
            while(i<n && nums[i] == nums[i-1])
                i++;
        }
        return ans;
        // Better: TC=O(n^3 * logv)
        // set<vector<int>> st;
        // for(int i=0; i<=n-4; i++){
        //     for(int j=i+1; j<=n-3; j++){
        //         unordered_set<int> hashSet;
        //         for(int k=j+1; k<=n-2; k++){
        //             int fourth = target - (nums[i] + nums[j] + nums[k]);
        //             if(hashSet.find(fourth) != hashSet.end()){
        //                 vector<int> quad = {nums[i], nums[j], nums[k], fourth};
        //                 sort(quad.begin(), quad.end());
        //                 st.insert(quad);
        //             }
        //             hashSet.insert(nums[k]);
        //         }
        //     }
        // }
        // vector<vector<int>> ans(st.begin(), st.end());
        // return ans;

        // Brute: TC=O(n^4 + mlogm + m)
        // set<vector<int>> st;
        // for(int i=0; i<=n-4; i++){
        //     for(int j=i+1; j<=n-3; j++){
        //         for(int k=j+1; k<=n-2; k++){
        //             for(int l=k+1; l<=n-1; l++){
        //                 if(nums[i] + nums[j] + nums[k] + nums[l] == target){
        //                     vector<int> quad = {nums[i], nums[j], nums[k], nums[l]};
        //                     sort(quad.begin(), quad.end());
        //                     st.insert(quad);
        //                 }
            
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>> ans(st.begin(), st.end());
        // return ans;
    }
};