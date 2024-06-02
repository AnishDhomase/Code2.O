class Solution {
    int reverse(int n){
        int revNum = 0;
        while(n>0){
            revNum = (revNum * 10) + n%10;
            n /= 10;
        }
        return revNum;
    }
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> st;
        for(auto num : nums){
            st.insert(num);
            st.insert(reverse(num));
        }
        return st.size();
    }
};