class Solution {
    // int indexOfCandleJustSmallerThan(int t, vector<int> arr){
    //     int n=arr.size(), low=0, high=n-1, mid, ans=-1;
    //     if(t < arr[0])
    //         return -1;
    //     while(low <= high){
    //         mid = (low + high)/2;
    //         if(arr[mid] == t){
    //             ans = mid;
    //             break;
    //         }
    //         else if(arr[mid] < t){
    //             ans = mid;
    //             low = mid+1;
    //         }
    //         else{
    //             high = mid-1;
    //         }
    //     }
    //     return ans;
    // }
    // int indexOfCandleJustBiggerThan(int t, vector<int> arr){
    //     int n=arr.size(), low=0, high=n-1, mid, ans=-1;
    //     if(arr[n-1] < t)
    //         return -1;
    //     while(low <= high){
    //         mid = (low + high)/2;
            
    //         if(t == arr[mid]){
    //             ans = mid;
    //             break;
    //         }
    //         else if(t < arr[mid]){
    //             ans = mid;
    //             high = mid-1;
    //         }
    //         else{
    //             low = mid+1;
    //         }
    //     }
    //     return ans;
    // }
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int qn = queries.size(), n = s.length();
        vector<int> ans(qn,0), prevDash(n,-1),  nextDash(n,n);
        unordered_map<int,int>  dash;
        int lastDashInd = -1;
        for(int i=0; i<n; i++){
            if(s[i]=='|'){
                lastDashInd ++; 
                dash[i] = lastDashInd;
            }
        }
        if(lastDashInd < 1)
            return ans;

        int prevDashInd = -1, nextDashInd = n;
        for(int i=0; i<n; i++){
            if(s[i]=='|'){
                prevDashInd = i;
            }
            prevDash[i] = prevDashInd;
        }
        for(int i=n-1; i>=0; i--){
            if(s[i]=='|'){
                nextDashInd = i;
            }
            nextDash[i] = nextDashInd;
        }

        for(int i=0; i<qn; i++){
            int lb = queries[i][0];
            int ub = queries[i][1];
            if(lb == ub)    continue;

            int low = nextDash[lb];
            if(low == n || ub < low)
                continue;

            int high = prevDash[ub];
            if(high == -1 || high < lb)
                continue;

            int platesBtn = (high-low) - (dash[high]-dash[low]);
            ans[i] = platesBtn;
        }
        return ans;
        
        // O(n * 2logn) --> TLE
        // int qn = queries.size();
        // vector<int> dash, ans(qn,0);
        // for(int i=0; i<s.length(); i++){
        //     if(s[i]=='|')
        //         dash.push_back(i);
        // }
        // if(dash.size() < 2)
        //     return ans;
        // for(int i=0; i<qn; i++){
        //     int lb = queries[i][0];
        //     int ub = queries[i][1];
        //     if(lb == ub)    continue;

        //     int low = indexOfCandleJustBiggerThan(lb, dash);
        //     if(low == -1 || ub < dash[low])
        //         continue;

        //     int high = indexOfCandleJustSmallerThan(ub, dash);
        //     if(high == -1 || dash[high] < lb)
        //         continue;

        //     int platesBtn = (dash[high]-dash[low]) - (high-low);
        //     ans[i] = platesBtn;
        // }
        // return ans;
    }
};