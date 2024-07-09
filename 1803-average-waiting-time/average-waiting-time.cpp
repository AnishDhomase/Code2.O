class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long time = 0, sumOfWaitingTimes = 0, n = customers.size();
        for(auto customer : customers){
            time = max <long long>(time, customer[0]);
            time += customer[1];
            sumOfWaitingTimes += (time - customer[0]);
        }
        double avg = (double) sumOfWaitingTimes / n;
        return avg;
    }
};