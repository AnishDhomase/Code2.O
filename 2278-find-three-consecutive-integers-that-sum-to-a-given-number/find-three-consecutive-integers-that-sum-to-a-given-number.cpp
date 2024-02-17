class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans;
        int rem = num % 3;
        if(rem) return ans;
        long long quotient = num/3;
        ans.push_back(quotient-1);
        ans.push_back(quotient);
        ans.push_back(quotient+1);
        return ans;

    }
};