class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> map; 

        for (int i : nums) {
            map[i]++;

            if (map[i] == nums.size()/3 + 1) ans.push_back(i);
        }
        return ans;
    }
};