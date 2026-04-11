class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
vector<int> ans;
for(auto i:asteroids){
    if(i>0)ans.push_back(i);
    else{
        while(!ans.empty() and ans.back()>0 and ans.back()<-i){
            ans.pop_back();
        }
        if(ans.empty() or ans.back()<0)ans.push_back(i);
        if(ans.size() and ans.back()==abs(i)){ans.pop_back();}
    }
}
    return ans;
    }
};