class Solution {
    bool isOverlapping(vector<int> intervals, vector<int> &ivl){
        if(intervals[0] <= ivl[1]){
            if(ivl[1] < intervals[1])  ivl[1] = intervals[1];
            return true;
        }
        return false;
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        vector<int> ivl(2);
        int n=intervals.size(), i=0, j;
        while(i<n){
            j=i+1;
            ivl[0] = intervals[i][0];
            ivl[1] = intervals[i][1];
            while(j<n && isOverlapping(intervals[j], ivl))
                j++;
            i=j;
            ans.push_back(ivl);
        }
        return ans;
    }
};