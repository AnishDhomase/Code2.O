class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int ct = 0;
        for(auto num: arr){
            if(num%2 == 1)  ct ++;
            else            ct = 0;
            if(ct == 3) return true;
        }
        return false;
    }
};