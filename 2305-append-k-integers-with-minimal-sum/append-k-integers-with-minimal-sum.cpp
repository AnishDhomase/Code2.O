class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i=0, n = nums.size(), K=k;
        long long num = 1, sum = 0;
        while(i < n && K > 0) {
            bool flag = false;
            while(i < n && nums[i] == num){
                i ++;
                flag = true;
            }
            if(flag){
                num ++;
                continue;
            }
            else {
                while(K > 0 && nums[i] != num){
                    K --;
                    sum += num;
                    num ++;
                }
            }
            
        }
        while(K > 0){
            sum += num;
            K --;
            num ++;
        }
        return sum;
    }
};