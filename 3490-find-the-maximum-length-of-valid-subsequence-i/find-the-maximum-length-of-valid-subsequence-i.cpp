class Solution {
    int etMaxOddEvenSubSeq(vector<int>& nums){
        int n = nums.size(), len = 1, prev = 0;
        for(int i=1; i<n; i++){
            if(nums[i]%2 != nums[prev]%2){
                prev = i;
                len ++;
            }
        }
        return len;
    }
    int etMaxOddOrEvenSubSeq(vector<int>& nums){
        int odd, even;
        odd = even = 0;
        for(auto num: nums){
            if(num % 2 == 0)  even ++;
            else              odd ++;
        }
        return max(odd, even);
    }
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = etMaxOddOrEvenSubSeq(nums);
        int x = etMaxOddEvenSubSeq(nums);
        return max(x, maxLen);
    }
};