class Solution {
    int getMinDays(int oranges){
        if(oranges <= 1)    return oranges;

        int w1 = (oranges % 3) + getMinDays(oranges/3);
        int w2 = (oranges % 2) + getMinDays(oranges/2);
        return 1 + min(w1, w2);
    }
public:
    int minDays(int n) {
        return getMinDays(n);
    }
};