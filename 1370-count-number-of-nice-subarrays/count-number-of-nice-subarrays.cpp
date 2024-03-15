class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), ans=0;
        vector<int> odds;
        for(int i=0; i<n; i++){
            if(nums[i]%2)
                odds.push_back(i);
        }
        int osz = odds.size();
        for(int i=0, j=k-1; j<osz; i++,j++){
            int leftOdd=-1, rightOdd=n;
            if(i!=0)
                leftOdd = odds[i-1];
            if(j!=osz-1)
                rightOdd = odds[j+1];
            int l = odds[i] - leftOdd;
            int r = rightOdd - odds[j] ;
            ans += l * r;
        }
        return ans;
    }
};