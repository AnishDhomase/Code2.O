class Solution {
public:
    bool canChange(string start, string target) {
        int i, j, n = start.length();
        i = j = 0;
        while(i<n && j<n){
            if(target[j] == '_'){
                j ++;
                continue;
            } 
            if(start[i] == '_'){
                i ++;
                continue;
            } 
            if(target[j] != start[i])   return false;
            if(target[j] == 'L' && i<j) return false;
            if(target[j] == 'R' && i>j) return false;
            i ++;
            j ++;
        }
        while(i<n){
            if(start[i] != '_') return false;
            i ++;
        }
        while(j<n){
            if(target[j] != '_') return false;
            j ++;
        }
        return true;
    }
};