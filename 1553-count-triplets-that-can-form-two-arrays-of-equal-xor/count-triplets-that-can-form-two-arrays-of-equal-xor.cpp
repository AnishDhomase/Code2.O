class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int a=0, b=0, count=0, n=arr.size();
        for(int i=0; i<=n-2; i++){
            a = arr[i];
            for(int j=i+1; j<=n-1; j++){
                for(int k=j; k<=n-1; k++){
                    b ^= arr[k];
                    if(a == b)  count++;
                }
                a ^= arr[j];
                b = 0;
            }
        }
        return count;
    }
};