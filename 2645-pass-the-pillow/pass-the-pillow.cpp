class Solution {
public:
    int passThePillow(int n, int time) {
        int rounds = time / (n-1), remainingPasses = time % (n-1);
        return (rounds % 2 == 0) ? (1 + remainingPasses) : (n - remainingPasses);   
    }
};