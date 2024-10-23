class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), maxA = 0;
        stack<int> st;
        for(int i=0; i<n; i++){
            while(st.size() > 0 && heights[st.top()] > heights[i]){
                int currI = st.top();
                st.pop();
                int prevSmallerInd = st.size() > 0 ? st.top() : -1;
                int area = (i - prevSmallerInd - 1) * heights[currI];
                maxA = max(maxA, area);
            }
            st.push(i);
        }
        while(st.size() > 0){
            int currI = st.top();
            st.pop();
            int prevSmallerInd = st.size() > 0 ? st.top() : -1;
            int area = (n - prevSmallerInd - 1) * heights[currI];
            maxA = max(maxA, area);
        }
        return maxA;
        
    }
};