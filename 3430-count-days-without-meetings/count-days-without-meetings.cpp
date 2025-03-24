class Solution {
    bool isInterSectingIntervals(int s1, int e1, int s2, int e2){
        return s1 <= s2 && s2 <= e1;
    }
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int n = meetings.size();
        int freeDays = days;
        int start = meetings[0][0], end = meetings[0][1];
        for(int i=1; i<n; i++){
            vector<int> meeting = meetings[i];
            if(isInterSectingIntervals(start, end, meeting[0], meeting[1]))
                end = max(end, meeting[1]);
            else{
                freeDays -= end - start + 1;
                start = meeting[0];
                end = meeting[1];
            }
        }
        freeDays -= end - start + 1;
        return freeDays;
    }
};