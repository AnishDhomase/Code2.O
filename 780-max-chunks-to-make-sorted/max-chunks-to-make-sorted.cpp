class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> smallestToRight(n);
        for(int i=n-1, s=1e9; i>=0; i--){
            smallestToRight[i] = s;
            s = min(s, arr[i]);
        }
        int i=0, elem=arr[0], chunks=0;
        while(i < n){
            if(elem > smallestToRight[i]){
                elem = max(elem, arr[i]);
                i++;
            }   
            else{
                chunks ++;
                i++;
                if(i < n)
                    elem = arr[i];
            }
        }
        return chunks;
    }
};