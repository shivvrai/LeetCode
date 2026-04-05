class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int>indegree(numCourses);
        vector<vector<int>>adj(numCourses);
        for(auto i:pre){
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(!indegree[i])
            q.push(i);
        }
        vector<int>ans;
        vector<int>ans1;
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto j:adj[node]){
                indegree[j]--;
                if(!indegree[j])q.push(j);
            }
        }
        return (ans.size()==numCourses? ans : ans1);

    }   
};