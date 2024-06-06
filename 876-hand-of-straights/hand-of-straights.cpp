class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0)  return false;
        map<int,int> freq;
        for(auto e : hand)  freq[e]++;
        while(n){
            int currElem = (*freq.begin()).first;
            freq[currElem] --;
            if(freq[currElem] == 0) freq.erase(currElem);
            for(int i=2; i<=groupSize; i++){
                int nextConsecutiveElem = currElem + 1;
                if(freq[nextConsecutiveElem] == 0)  return false;
                freq[nextConsecutiveElem] --;
                if(freq[nextConsecutiveElem] == 0) freq.erase(nextConsecutiveElem);
                currElem = nextConsecutiveElem;
            }
            n -= groupSize;
        }
        return true;
    }
};