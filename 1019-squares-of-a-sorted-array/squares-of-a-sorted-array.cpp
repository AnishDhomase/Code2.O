class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(), fp=n;
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(0 <= nums[i]){
                fp = i;
                break;
            }
        }
        int pos = fp, neg;
        neg = pos-1;

        while(0 <= neg && pos < n){
            int sqPos = nums[pos] * nums[pos];
            int sqNeg = nums[neg]  *nums[neg];
            if(sqNeg < sqPos){
                ans.push_back(sqNeg);
                neg--;
            }
            else{
                ans.push_back(sqPos);
                pos++;
            }
        }
        while(pos < n){
            int sqPos = nums[pos] * nums[pos];
            ans.push_back(sqPos);
            pos++;
        }
        while(0 <= neg){
            int sqNeg = nums[neg]  *nums[neg];
            ans.push_back(sqNeg);
            neg--;
        }
        return ans;
    }
};