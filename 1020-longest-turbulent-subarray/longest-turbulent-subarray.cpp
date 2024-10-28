class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int s = 0, e = 1, delta = 0, maxL = 1, n = arr.size(); 
        while(e < n){
            if(e-s == 1){
                int adjDiff = arr[e]-arr[s];
                delta = adjDiff == 0 ? 0 : (adjDiff < 0 ? -1 : 1);
                if(delta == 0){
                    s ++;
                    e ++;
                }
                else    e ++;
            }
            else{
                int reqDelta = - delta;
                int adjDiff = arr[e]-arr[e-1];
                int curDelta = adjDiff == 0 ? 0 : (adjDiff < 0 ? -1 : 1);
                if(reqDelta == curDelta){
                    delta = - delta;
                    e ++;
                } 
                else{
                    maxL = max(maxL, e-s);
                    s = e-1;
                }
            }
        }
        maxL = max(maxL, e-s);
        return maxL;
    }
};