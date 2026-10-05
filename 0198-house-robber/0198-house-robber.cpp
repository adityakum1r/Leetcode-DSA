class Solution {
public:
    int solve(vector<int>& nums,int idx,vector<int>&dp){
        // base case
        if(idx>=nums.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        // recursive fn
        int take = nums[idx] + solve(nums,idx+2,dp);
        int notake = solve(nums,idx+1,dp);
        return dp[idx] =max(take,notake);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return solve(nums,0,dp);
    }
};