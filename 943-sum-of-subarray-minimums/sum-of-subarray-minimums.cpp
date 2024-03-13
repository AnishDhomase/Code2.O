class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long sumMins = 0;
        int n = arr.size(), mod = 1e9+7;
        vector<int> nextSmlRight(n,n), nextSmlLeft(n,-1); //indices
        stack<pair<int,int>> st, st1; //{elem,index}
        for(int i=n-1; i>=0; i--){
            while(st.size() && st.top().first >= arr[i]){
                st.pop();
            }
            if(st.size()){
                nextSmlRight[i] = st.top().second;
            }
            st.push({arr[i],i});
        }
        for(int i=0; i<n; i++){
            while(st1.size() && st1.top().first > arr[i]){
                st1.pop();
            }
            if(st1.size()){
                nextSmlLeft[i] = st1.top().second;
            }
            st1.push({arr[i],i});
        }
        for(int i=0; i<n; i++){
            long long NumOfArrayInWhichCurrElemIsMin = (i-nextSmlLeft[i]) * (nextSmlRight[i]-i);
            sumMins = (sumMins + NumOfArrayInWhichCurrElemIsMin * arr[i]) % mod;
        }
        return sumMins;

    }
};