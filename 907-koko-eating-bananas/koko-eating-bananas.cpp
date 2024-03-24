class Solution {
    bool iskmidEnough(int speed, vector<int> piles, int h){
        int hrs = 0;
        for(auto p : piles){
            hrs += p/speed;
            if(p % speed) hrs+=1;
            if(hrs > h) return false;
        }
        return true;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int BiggestPile = 1, ans;
        for(auto p : piles)
            BiggestPile = max(BiggestPile, p);

        int klow = 1, khigh = BiggestPile;
        while(klow <= khigh){
            int kmid = klow + (khigh-klow)/2;
            bool enough = iskmidEnough(kmid, piles, h);
            if(enough){  
                khigh = kmid - 1;
                ans = kmid;
            }
            else    klow = kmid + 1;
        }
        return ans;
    }
};