class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> partLenths;
        unordered_map<char,int> totalFreq;
        unordered_map<char,int> freqInPart;
        for(auto ch: s)
            totalFreq[ch] ++;
        int lenOfPart = 0;
        for(auto ch: s){
            freqInPart[ch] ++;
            lenOfPart ++;
            bool validPart = true;

            for(auto it: freqInPart){
                char chOfPart = it.first, numOfOccInPart = it.second;
                if(numOfOccInPart != totalFreq[chOfPart]){
                    validPart = false;
                    break;
                }
            }

            if(!validPart) continue;
            partLenths.push_back(lenOfPart);
            lenOfPart = 0;
            freqInPart.clear();
        }
        return partLenths;
    }
};