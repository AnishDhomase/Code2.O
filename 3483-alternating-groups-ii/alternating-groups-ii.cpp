class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int s=0, i=1, n=colors.size(), streak = 1, cnt = 0;
        while(i!=s){
            int currentClr = colors[i], prevClr = colors[(i-1+n)%n];
            if(currentClr != prevClr){
                streak ++;
                i = (i+1)%n;
            }
            else{
                if(i < s)   break;
                // add to ans
                if(streak >= k) cnt += streak-k+1;
                // reset streak
                streak = 1;
                s = i;

                i = (i+1)%n; 
            }
        }
        // add last streak to ans
        if(streak == n && colors[(i-1+n)%n] != colors[s]) return n;
        if(i <= s) cnt -= i-k+1 > 0 ? i-k+1 : 0;
        if(streak >= k) cnt += streak-k+1;
        return cnt;
    }
};