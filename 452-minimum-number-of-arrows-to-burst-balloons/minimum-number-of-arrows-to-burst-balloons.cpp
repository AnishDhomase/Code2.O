class Solution {
    bool isOverlapping(vector<int> points, vector<int> &ivl){
        if(points[0] <= ivl[1]){
            ivl[0] = points[0];
            if(points[1] < ivl[1])  ivl[1] = points[1];
            return true;
        }
        return false;
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<int> ivl(2);
        int n=points.size(), arr=0, i=0, j;
        while(i<n){
            arr++;
            j=i;
            ivl[0] = points[i][0];
            ivl[1] = points[i][1];
            while(j<n && isOverlapping(points[j], ivl))
                j++;
            i=j;
        }
        return arr;
        
    }
};