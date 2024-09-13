class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), sz, dy, dx, cnt, maxP=2;
        if(n == 1)  return 1;
        for(int i=0; i<n-1; i++){
            vector<pair<int,int>> slopes;
            for(int j=i+1; j<n; j++){
                dy = points[j][1] - points[i][1];
                dx = points[j][0] - points[i][0];
                slopes.push_back({dy,dx});
            }
            sz = slopes.size();
            for(int p=0; p<sz-1; p++){
                cnt = 0; 
                for(int k=p+1; k<sz; k++){
                    if(slopes[p].first * slopes[k].second == slopes[p].second * slopes[k].first)
                        cnt ++;
                }
                maxP = max(maxP, cnt + 2);
            }
        }
        return maxP;
    }
};