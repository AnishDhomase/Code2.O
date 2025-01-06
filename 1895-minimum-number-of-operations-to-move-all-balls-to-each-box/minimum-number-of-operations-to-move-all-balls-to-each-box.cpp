class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> ans(n, 0), left(n, 0), right(n, 0);
        int balls = boxes[0] == '1';
        for(int i=1; i<n; i++){
            left[i] = left[i-1] + balls;
            if(boxes[i] == '1') balls ++;
        }
        balls = boxes[n-1] == '1';
        for(int i=n-2; i>=0; i--){
            right[i] = right[i+1] + balls;
            if(boxes[i] == '1') balls ++;
        }
        for(int i=0; i<n; i++)
            ans[i] = left[i] + right[i];
        
        return ans;
    }
};