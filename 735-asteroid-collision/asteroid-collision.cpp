class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans, ans1;
        stack<int> st;
        int n = asteroids.size();
        for(int i=n-1; i>=0; i--){
            bool flag = true;
            if(asteroids[i] < 0)
                st.push(abs(asteroids[i]));
            else{
                while(st.size() && st.top() < asteroids[i])
                    st.pop();
                if(st.size() && st.top() == asteroids[i]){
                    st.pop();
                    flag = false;
                }
                else if(st.size() && st.top() > asteroids[i])
                    flag = false;
                if(flag)
                    ans.push_back(asteroids[i]);
            }
        }
        while(st.size()){
            ans1.push_back(-1 * st.top());
            st.pop();
        } 
        reverse(ans.begin(), ans.end());
        for(auto e : ans)
            ans1.push_back(e);
        return ans1;
    }
};