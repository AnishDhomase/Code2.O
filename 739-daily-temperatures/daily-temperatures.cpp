class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        stack<pair<int,int>> S;
        for(int i=n-1; i>=0; i--){
            while(S.size() && S.top().first <= temperatures[i]){
                S.pop();
            }
            if(S.size())
                ans[i] = S.top().second - i;
            S.push({temperatures[i],i});
        }
        return ans;
    }
};