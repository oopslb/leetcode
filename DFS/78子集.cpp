/*
采用回溯法，对于每一位都可以选择存或者不存。
*/

class Solution {
public:
    void dfs(int idx,vector<int>& nums,vector<vector<int>>& ans,vector<int>res){
        ans.push_back(res);
        if(idx>=nums.size()){
            return;
        }
        for(int i=idx;i<nums.size();i++){
            res.push_back(nums[i]);
            dfs(i+1,nums,ans,res);
            res.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        dfs(0,nums,ans,{});
        return ans;
    }
};
