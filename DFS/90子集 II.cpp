/*
排个序，相同的只取一次即可
*/
class Solution {
public:
    void dfs(int idx,vector<int> nums,vector<int>res,vector<vector<int>>&ans){
        ans.push_back(res);
        if(idx>=nums.size()){
            return;
        }
        for(int i=idx;i<nums.size();i++){
            if(i>idx&&nums[i]==nums[i-1]){
                continue;
            }
            res.push_back(nums[i]);
            dfs(i+1,nums,res,ans);
            res.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         sort(nums.begin(),nums.end());
         vector<vector<int>>ans;
         dfs(0,nums,{},ans);
         return ans;

    }
};
