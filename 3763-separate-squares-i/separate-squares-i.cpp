class Solution {
    double isEqualDivisionOfArea(double pos, vector<vector<int>>& squares){
        double areaAbovePos = 0, areaBelowPos = 0;
        for(auto &sq: squares){
            int l = sq[2], y1 = sq[1], y2 = y1 + l;
            if(y2 <= pos) areaBelowPos += (double) l*l;
            else if(y1 >= pos) areaAbovePos += (double) l*l;
            else{
                double lAbove = y2-pos, lBelow = pos-y1;
                areaBelowPos += (double) l*lBelow;
                areaAbovePos += (double) l*lAbove;
            }
        }
        return areaAbovePos - areaBelowPos;
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 2e9, high = 0;
        for(auto &sq: squares){
            int l = sq[2], y1 = sq[1], y2 = y1 + l;
            low = min<double>(low, y1);
            high = max<double>(high, y2);
        }
        while(high-low > 1e-5){
            double mid = (low + high) / 2.0;
            double result = isEqualDivisionOfArea(mid, squares);
            if(result > 0)      low = mid;
            else                high = mid;
        }
        return high;
    }
};