class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> ans(n, 0), left(n, 0), right(n, 0);
        int balls = boxes[0] == '1', steps = 0;
        for(int i=1; i<n; i++){
            ans[i] = steps + balls;
            steps = ans[i];
            if(boxes[i] == '1') balls ++;
        }
        balls = boxes[n-1] == '1';
        steps = 0;
        for(int i=n-2; i>=0; i--){
            steps += balls;
            ans[i] += steps;
            if(boxes[i] == '1') balls ++;
        }
       
        
        return ans;
    }
};