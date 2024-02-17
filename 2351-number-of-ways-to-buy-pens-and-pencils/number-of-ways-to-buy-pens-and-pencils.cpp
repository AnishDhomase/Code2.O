class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ways = 0;
        for(int pen=0; ; pen++){
            long long remMoney = total - pen*cost1;
            if(remMoney < 0)   break;
            long long pencil = remMoney/cost2;
            ways += pencil+1;
        }
        return ways;
    }
};