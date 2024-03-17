class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        bool inserted = false;
        if(intervals.size() == 0){
            ans.push_back(newInterval);
        }
        else if(newInterval[1] < intervals[0][0]){
            ans.push_back({newInterval[0], newInterval[1]});
            for(auto intrvl : intervals){
                ans.push_back(intrvl);
            }
        }
        else if(intervals[n-1][1] < newInterval[0]){
            intervals.push_back(newInterval);
            return intervals;
        }
        else{
            for(int i=0; i<n; i++){
                if(newInterval[0] < intervals[i][0]){
                    if(newInterval[1] <= intervals[i][1]){
                        if(newInterval[1] < intervals[i][0]){
                            break;
                        }
                        intervals[i][0] = newInterval[0];
                        return intervals;
                    }
                    else{
                        inserted = true;
                        intervals[i][0] = newInterval[0];
                        intervals[i][1] = newInterval[1];

                        for(int j=i; j<=n-2; j++){
                            if(intervals[j][1] >= intervals[j+1][0]){
                                intervals[j+1][0] = intervals[j][0];
                                if(intervals[j][1] > intervals[j+1][1]){
                                    intervals[j+1][1] = intervals[j][1];
                                }
                                intervals[j].clear();
                            }
                            else{
                                break;
                            }
                        }
                        break;
                    }
                }
                else if(newInterval[0] <= intervals[i][1]){
                    if(newInterval[1] > intervals[i][1]){
                        inserted = true;
                        intervals[i][1] = newInterval[1];
                        for(int j=i; j<=n-2; j++){
                            if(intervals[j][1] >= intervals[j+1][0]){
                                intervals[j+1][0] = intervals[j][0];
                                if(intervals[j][1] > intervals[j+1][1]){
                                    intervals[j+1][1] = intervals[j][1];
                                }
                                intervals[j].clear();
                            }
                            else{
                                break;
                            }
                        }
                        break;
                    }
                    else{
                        return intervals;
                    }
                }
            }
            if(inserted)
                for(auto intrvl : intervals){
                    if(intrvl.size())
                        ans.push_back(intrvl);
                }
            else{
                bool flag = false;
                for(auto intrvl : intervals){
                    if(newInterval[0] > intrvl[0] )
                        ans.push_back(intrvl);
                    else{
                        if(flag==false){
                            ans.push_back(newInterval);
                            flag = true;
                        }
                        ans.push_back(intrvl);
                    }
                }
            }
        }
        return ans;
    }
};