class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();int maxi=0;stack<int>st;
        for(int i=0;i<=n;i++){
        int h=(i==n?0:heights[i]);
            while(st.size() and h<heights[st.top()]){
                
                int height = heights[st.top()];
                st.pop();

                int right = i;
                int left = st.empty() ? -1 : st.top();

                int width = right - left - 1;

                maxi = max(maxi, height * width);
            }
            st.push(i);
        }
        return maxi;
    }
};