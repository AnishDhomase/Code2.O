class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0, r=0, maxL=0, n=nums.size(), K=k;
        queue<int> Q;
        while(r<n){
            if(nums[r] == 1){
                maxL = max(maxL, r-l+1);
                r ++;
            }
            else if(K > 0) {
                Q.push(r);
                K --;
                maxL = max(maxL, r-l+1);
                r ++;
            }
            else{
                if(Q.size() > 0){
                    l = Q.front() + 1;
                    Q.pop();
                    Q.push(r);
                }
                else l=r+1;
                r ++;
            }
        }
        return maxL;
    }
};