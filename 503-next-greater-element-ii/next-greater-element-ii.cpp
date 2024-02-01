class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1e9), inc;
        stack<int> S;
        for(int i=n-1; i>=0; i--){
            while(S.size() && S.top() <= nums[i])
                S.pop();
            if(S.size())
                ans[i] = S.top();
            S.push(nums[i]);
        }
        while(S.size()){
            inc.push_back(S.top());
            S.pop();
        }
        for(int i=0; i<n; i++){
            if(ans[i] == 1e9){
                bool isGreaterGot = false;
                for(auto e : inc){
                    if(nums[i] < e){
                        ans[i] = e;
                        isGreaterGot = true;
                        break;
                    }
                }
                if(!isGreaterGot)
                    ans[i] = -1;
            }
        }
        return ans;
    }
};