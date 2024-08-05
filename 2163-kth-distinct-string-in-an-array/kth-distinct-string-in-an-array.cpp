class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> freq;
        for(auto str: arr)
            freq[str] ++;
        int i=0;
        for(auto str: arr){
            if(freq[str] == 1){
                i++;
                if(i == k)
                    return str;
            }
        }
        return "";
    }
};