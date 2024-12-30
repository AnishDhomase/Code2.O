class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int prev = INT_MIN, distinct = 0;
        for(auto num: nums){
            if(num - k > prev){
                prev = num - k;
                distinct ++;
            }
            else{
                if(prev + 1 <= num + k){
                    prev = prev + 1;
                    distinct ++;
                }
            }
        }
        return distinct;

    }
};