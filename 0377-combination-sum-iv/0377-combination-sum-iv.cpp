class Solution {
public:
    int solve(vector<int>& nums,int target,int idx, vector<vector<int>>&dp){
        // base case
        if(target==0){
            return 1;
        }
        if(idx>=nums.size()){
            return 0;
        }
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
        //recursive fn
        int include = 0;
        if(nums[idx]<=target){
            include = solve(nums,target-nums[idx],0,dp);
        }
        int exclude = solve(nums,target,idx+1,dp);
        return dp[idx][target] = include+exclude;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        int idx=0;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(nums,target,idx,dp);
    }
};