class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0)  return false;
        map<int,int> freq;
        for(auto e : nums)  freq[e]++;
        while(n){
            int currElem = (*freq.begin()).first;
            freq[currElem] --;
            if(freq[currElem] == 0) freq.erase(currElem);
            for(int i=2; i<=k; i++){
                int nextConsecutiveElem = currElem + 1;
                if(freq[nextConsecutiveElem] == 0)  return false;
                freq[nextConsecutiveElem] --;
                if(freq[nextConsecutiveElem] == 0) freq.erase(nextConsecutiveElem);
                currElem = nextConsecutiveElem;
            }
            n -= k;
        }
        return true;
    }
};