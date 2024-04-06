class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ct = 0;
        int subArrSum = accumulate(arr.begin(), arr.begin()+k, 0);
        int minReqSum = k*threshold;
        int i=k, n=arr.size();
        if(subArrSum >= minReqSum)  ct++;
        while(i<n){
            subArrSum -= arr[i-k];
            subArrSum += arr[i];
            if(subArrSum >= minReqSum)  ct++;
            i++;
        }
        return ct;

    }
};