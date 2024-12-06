class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int cnt = 0;
        unordered_set<int> st(banned.begin(), banned.end());
        int sum = 0;
        for(int i=1; i<=n; i++){
            if(st.find(i) == st.end()){
                int newSum = sum + i;
                if(newSum > maxSum)
                    return cnt;
                sum = newSum;
                cnt ++;
            }
        }
        return cnt;
    }
};