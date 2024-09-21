class Solution {
    int beauty(unordered_map<char,int> &freq){
        int minV=1e9, maxV=-1;
        for(auto it : freq){
            minV = min(minV, it.second);
            maxV = max(maxV, it.second);
        }
        return maxV - minV;
    }
public:
    int beautySum(string s) {
        int sum = 0, n = s.length();
        for(int i=0; i<n; i++){
            unordered_map<char,int> freq;
            for(int j=i; j<n; j++){
                freq[s[j]] ++;
                sum += beauty(freq);
            }
        }
        return sum;
    }
};