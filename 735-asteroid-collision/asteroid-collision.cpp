class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> st;
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] < 0) {

                while (!st.empty() && st.top() > 0 && st.top() < abs(arr[i])) {
                    st.pop();
                }

                if (st.empty() || st.top() < 0) {
                    st.push(arr[i]);
                }  if (st.top() == abs(arr[i])) {
                    st.pop();
                }

            } else {
                st.push(arr[i]);
            }
        }
        while (st.size()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};