class Solution {
    int getMin(string &timePoint){
        int hr = stoi(timePoint.substr(0, 2));
        int mn = stoi(timePoint.substr(3, 2));
        return (hr * 60) + mn;
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        int minDiff = 1e9;
        map<int, int> mp;
        for(auto timePoint : timePoints){
            int min = getMin(timePoint);
            if(mp[min]) return 0;
            else mp[min] ++;
        }
        auto it1 = mp.begin();
        auto it2 = ++ mp.begin();
        while(it2 != mp.end()){
            int t1 = (*it1).first, t2 = (*it2).first;
            minDiff = min(minDiff, t2-t1);
            minDiff = min(minDiff, (24*60)-(t2-t1));
            it1 ++;
            it2 ++;
        }
        auto sIt = mp.begin();
        auto eIt = mp.rbegin();
        int t1 = (*sIt).first, t2 = (*eIt).first;
        minDiff = min(minDiff, t2-t1);
        minDiff = min(minDiff, (24*60)-(t2-t1));
        return minDiff;
    }
};