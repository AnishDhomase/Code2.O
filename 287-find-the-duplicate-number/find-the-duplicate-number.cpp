class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size()-1;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n+1; i++){
            if(nums[i]==nums[i+1])  return nums[i];
        }
        return 1;


        // int s=1, n=nums.size()-1, ct;
        // while(s<=n){
        //     ct=0;
        //     for(int i=0; i<n+1; i++){
        //         if(nums[i]==s)  ct++;
        //         if(ct==2)   return s;
        //     }
        //     s++;
        // }
        // return s;
    }
};