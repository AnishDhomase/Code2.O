class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i=0, j=0, cost=0, n=s.length(), ans=0;
        while(j<n){
            cost += abs(s[j]-t[j]);
            if(cost <= maxCost) j++;
            else {
                ans = max(ans, j-i);
                while(cost > maxCost){
                    cost -= abs(s[i]-t[i]);
                    i++;
                }
                j++;
            }
        }
        ans = max(ans, j-i);
        return ans;
    }
};