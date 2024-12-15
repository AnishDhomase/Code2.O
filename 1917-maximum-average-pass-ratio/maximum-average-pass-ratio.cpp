class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double,pair<int,int>>> maxHeap;
        double ration = 0;
        for(auto classs : classes){
            int pass = classs[0], total = classs[1];
            double prevRation = (double)pass/total;
            ration += prevRation;
            double newRation = (double)(pass+1)/(total+1);
            double change = newRation - prevRation;
            maxHeap.push({change, {pass, total}});
        }
        int extra = extraStudents;
        while(extra > 0){
            extra -= 1;
            auto topElem = maxHeap.top();
            maxHeap.pop();
            double increment = topElem.first;
            ration += increment; 

            int pass = topElem.second.first, total = topElem.second.second;
            double newRation = (double)(pass+1)/(total+1);
            double upcomingNewRation = (double)(pass+2)/(total+2);
            double newChange = upcomingNewRation - newRation;

            maxHeap.push({newChange, {pass+1, total+1}});  
        }
        double avgRation = (double)ration / n;
        return avgRation;
    }
};