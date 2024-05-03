class Solution {
public:
    int compareVersion(string version1, string version2) {
        string empty, rev;
        vector<string> v1, v2;
        for(auto d : version1){
            if(d != '.')
                rev += d;
            else{
                v1.push_back(rev);
                rev = empty;
            }
        }
        v1.push_back(rev);
        rev = empty;
        for(auto d : version2){
            if(d != '.')
                rev += d;
            else{
                v2.push_back(rev);
                rev = empty;
            }
        }
        v2.push_back(rev);
        int i=0, j=0;
        while(i<v1.size() && j<v2.size()){
            int r1 = stoi(v1[i]), r2 = stoi(v2[j]);
            if(r1 < r2) return -1;
            else if(r1 > r2)    return 1;
            i++; j++;
        }
        while(i < v1.size()){
            int r1 = stoi(v1[i]);
            if(r1!=0)   return 1;
            i++;
        }
        while(j < v2.size()){
            int r2 = stoi(v2[j]);
            if(r2!=0)   return -1;
            j++;
        }
        return 0;
        
    }
};