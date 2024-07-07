class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int fullBottles = numBottles, emptyBottles = 0, drunk = 0;
        while(fullBottles){
            drunk += fullBottles;

            emptyBottles += fullBottles % numExchange;
            fullBottles /= numExchange;
            
            fullBottles += emptyBottles / numExchange;
            emptyBottles %= numExchange;
        }
        return drunk;
    }
};