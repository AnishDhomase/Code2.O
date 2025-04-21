typedef long long LL;
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        LL prevValue, minValInSeq, maxValInSeq;
        minValInSeq = maxValInSeq = prevValue = lower;
        for(auto diff: differences){
            LL nextVal = (LL) prevValue + diff;
            minValInSeq = min<LL>(minValInSeq, nextVal);
            maxValInSeq = max<LL>(maxValInSeq, nextVal);
            prevValue = nextVal;
        }
        if(minValInSeq < lower){
            LL diff = (LL) lower - minValInSeq;
            minValInSeq += diff;  
            maxValInSeq += diff;  
        }
        return maxValInSeq <= upper ? upper-maxValInSeq+1 : 0;
    }
};