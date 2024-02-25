class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int sz1 = s1.length(), sz2 = s2.length();
        unordered_map<char,int> freq1; //{char,freq}
        for(auto ch : s1){
            freq1[ch]++;
        }
        for(int i=0; i<sz2; ){
            unordered_map<char,int> tmp = freq1;
            int len = 0;
            for(int j=i; j<sz2; j++){
                if(tmp[s2[j]]){
                    tmp[s2[j]]--;
                    len++;
                    if(len == sz1)
                        return true;
                }
                else{
                    break;
                }    
            }
            i++;
        }
        return false;
    }
};