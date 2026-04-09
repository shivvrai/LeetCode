class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n=arr.size();
        vector<int>nge(2*n,-1);
        stack<int>st;

        for(int i=2*n-1;i>=0;i--){
            int ind=i%n;
            if(st.empty()){
                nge[i]=-1;
                st.push(arr[ind]);

            }
            else{
                if(arr[ind]<st.top()){
                    nge[i]=st.top();
                    st.push(arr[ind]);
                }
                else{
                    while(!st.empty() and arr[ind]>=st.top()){
                        st.pop();
                        }
                    if(st.empty())nge[i]=-1;else nge[i]=st.top();
                    st.push(arr[ind]);
                }
            }
            
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(nge[i]);
        }
        return ans;
    }
};